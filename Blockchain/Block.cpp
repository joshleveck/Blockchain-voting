#include "Block.h"
#include "../SHA256/sha256.h"
#include <sstream>
#include <vector>
#include <ctime>

Block::Block(uint32_t index_in, const std::vector<int> &data_in) : _index(index_in), _data(data_in)
{
    _nonce = -1;
    _time = std::time(nullptr);
}

std::string Block::get_hash()
{
    return _hash;
}

std::string Block::get_prev_hash()
{
    return _prev_hash;
}

void Block::set_prev_hash(std::string hash)
{
    _prev_hash = hash;
}

void Block::mine_block(uint32_t difficulty)
{
    std::string str(difficulty, '0');
    str[difficulty] = '\0';

    while (_hash.substr(0, difficulty) != str)
    {
        ++_nonce;
        _hash = _calculate_hash();
    }
}

inline std::string Block::_calculate_hash() const
{
    std::stringstream ss;
    ss << _index << _time;
    for (int i = 0; i < _data.size(); ++i)
    {
        ss << _data[i];
    }
    ss << _nonce << _prev_hash;

    return sha256(ss.str());
}

std::vector<int> Block::get_data()
{
    return _data;
}
#include <cstdint>
#include <iostream>
#include <vector>

class Block
{
public:
    Block(uint32_t index_in, const std::vector<int> &data_in);
    std::string get_prev_hash();
    void set_prev_hash(std::string hash);
    std::string get_hash();
    void mine_block(uint32_t difficulty);
    std::vector<int> get_data();

private:
    uint32_t _index;
    int64_t _nonce;
    std::vector<int> _data;
    std::string _prev_hash;
    std::string _hash;
    time_t _time;

    std::string _calculate_hash() const;
};
#include "Blockchain.h"
#include <iostream>
#include <vector>

Blockchain::Blockchain()
{
    _chain.emplace_back(Block(0, std::vector<int>()));
    _difficulty = 5;
}

void Blockchain::add_block(Block new_block)
{
    new_block.set_prev_hash(_get_last_block().get_hash());
    new_block.mine_block(_difficulty);
    _chain.push_back(new_block);
}

Block Blockchain::_get_last_block() const
{
    return _chain.back();
}

std::vector<Block> Blockchain::get_chain()
{
    return _chain;
}

void Blockchain::print_blockchain()
{
    for (int i = 0; i < _chain.size(); ++i)
    {
        std::cout << "Block " << i << " ";
        for (int j = 0; j < _chain[i].get_data().size(); ++j)
        {
            std::cout << _chain[i].get_data()[j] << " ";
        }
        std::cout << std::endl;
    }
}
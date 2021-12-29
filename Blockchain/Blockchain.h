#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain
{
public:
    Blockchain();
    void add_block(Block new_block);
    void print_blockchain();
    std::vector<Block> get_chain();

private:
    uint32_t _difficulty;
    std::vector<Block> _chain;
    Block _get_last_block() const;
};
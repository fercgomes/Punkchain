#include <memory>
#include <string>
#include <vector>
#include "block.hpp"
#include "transaction.hpp"

class Chain
{
private:
    // Transaction pool (mempool)
    std::vector<std::unique_ptr<Transaction>> pool;
    std::vector<std::unique_ptr<Block>>       blocks;

public:
};

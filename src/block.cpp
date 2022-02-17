#include "./block.hpp"
#include <sstream>
#include <time.h>
#include "utils.hpp"

Block::Block(std::string lastHash) : lastHash(lastHash) {}

void Block::Hash()
{
    std::time_t timestamp = std::time(nullptr);
    this->timestamp       = timestamp;

    std::stringstream ss;
    ss << timestamp << lastHash << nonce << difficulty;
    std::string serializedBlock = ss.str();

    // either hash all the transactions, or append merkle root here

    hash = Utils::HashString(serializedBlock);
}

std::string Block::GetHash() const noexcept { return hash; }

Block Genesis()
{
    Block genesis(std::string("0000000000000000000000000000000000"));
    genesis.Hash();
    return genesis;
}
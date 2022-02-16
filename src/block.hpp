#pragma once
#include <inttypes.h>
#include <string>
#include "transaction.hpp"

class Block
{
private:
    uint32_t    timestamp;
    std::string lastHash;
    std::string hash;
    uint32_t    nonce;
    uint32_t    difficulty;

    // Will store all transactions within the block
    std::vector<Transaction> transactions;

public:
    Block(uint32_t timestamp, std::string lastHash, std::string hash, uint32_t nonce,
          uint32_t difficulty);
};

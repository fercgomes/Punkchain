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
    uint64_t    nonce      = 0;
    uint32_t    difficulty = 2;

    // Will store all transactions within the block
    std::vector<Transaction> transactions;

public:
    Block(std::string lastHash);

    void        Hash();
    std::string GetHash() const noexcept;
};

Block Genesis();

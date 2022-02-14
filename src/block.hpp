#pragma once
#include <inttypes.h>
#include <string>

namespace Punkchain
{
class Block
{
private:
    uint32_t    timestamp;
    std::string lastHash;
    std::string hash;
    std::string data;
    uint32_t    nonce;
    uint32_t    difficulty;

public:
    Block(uint32_t timestamp, std::string lastHash, std::string hash, uint32_t nonce,
          uint32_t difficulty);
};
} // namespace Punkchain

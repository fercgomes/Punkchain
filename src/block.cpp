#include "./block.hpp"

Block::Block(uint32_t timestamp, std::string lastHash, std::string hash, uint32_t nonce,
             uint32_t difficulty)
    : timestamp(timestamp), lastHash(lastHash), hash(hash), nonce(nonce), difficulty(difficulty)
{
}
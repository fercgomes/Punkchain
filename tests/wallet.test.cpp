#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <wallet.hpp>
#include "doctest.h"

TEST_CASE("Wallet signs and verify a message")
{
    Wallet      wallet;
    std::string message = "test message";
    std::string signature;

    wallet.SignMessage(message, signature);

    CHECK(wallet.VerifyMessage(wallet.GetPublicKey(), message, signature));
}

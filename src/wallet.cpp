#include "wallet.hpp"
#include <aes.h>
#include <assert.h>
#include <eccrypto.h>
#include <files.h>
#include <filters.h>
#include <fmt/format.h>
#include <integer.h>
#include <iostream>
#include <oids.h>
#include <osrng.h>
#include <sha.h>
#include "utils.hpp"

using CryptoPP::ECDSA;
using CryptoPP::ECP;
using CryptoPP::SHA1;

Wallet::Wallet()
{
    std::cout << "Init wallet" << std::endl;
    GeneratePrivateKey();
    GeneratePublicKey();

    Utils::PrintPublicKey(publicKey);
    Utils::PrintPrivateKey(privateKey);
}

ECDSA<ECP, SHA1>::PublicKey Wallet::GetPublicKey() { return publicKey; }

void Wallet::GeneratePrivateKey()
{
    CryptoPP::AutoSeededRandomPool prng;
    const CryptoPP::OID&           oid = CryptoPP::ASN1::secp160r1();

    privateKey.Initialize(prng, oid);
    assert(privateKey.Validate(prng, 3)); // sanity check
}

void Wallet::GeneratePublicKey()
{
    CryptoPP::AutoSeededRandomPool prng;
    assert(privateKey.Validate(prng, 3));

    privateKey.MakePublicKey(publicKey);
    assert(publicKey.Validate(prng, 3));
}

bool Wallet::SignMessage(const std::string& message, std::string& signature)
{
    CryptoPP::AutoSeededRandomPool prng;
    signature.erase();

    CryptoPP::StringSource(
        message, true,
        new CryptoPP::SignerFilter(prng, ECDSA<ECP, SHA1>::Signer(privateKey),
                                   new CryptoPP::StringSink(signature)) // SignerFilter
    );                                                                  // StringSource
    return !signature.empty();
}

bool Wallet::VerifyMessage(const ECDSA<ECP, SHA1>::PublicKey& key, const std::string& message,
                           std::string& signature)
{
    bool result = false;

    CryptoPP::StringSource(
        signature + message, true,
        new CryptoPP::SignatureVerificationFilter(
            ECDSA<ECP, SHA1>::Verifier(key),
            new CryptoPP::ArraySink((CryptoPP::byte*)&result,
                                    sizeof(result))) // SignatureVerificationFilter
    );

    return result;
}

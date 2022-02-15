#include <eccrypto.h>
#include <osrng.h>
#include <sha.h>

using CryptoPP::ECDSA;
using CryptoPP::ECP;
using CryptoPP::SHA1;

class Wallet
{
private:
    ECDSA<ECP, SHA1>::PrivateKey privateKey;
    ECDSA<ECP, SHA1>::PublicKey  publicKey;

    void GeneratePrivateKey();
    void GeneratePublicKey();

public:
    Wallet();

    ECDSA<ECP, SHA1>::PublicKey GetPublicKey();

    bool SignMessage(const std::string& message, std::string& signature);

    bool VerifyMessage(const ECDSA<ECP, SHA1>::PublicKey& key, const std::string& message,
                       std::string& signature);
};
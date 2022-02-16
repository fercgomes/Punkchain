#pragma once

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

using CryptoPP::DL_GroupParameters_EC;
using CryptoPP::ECDSA;
using CryptoPP::ECP;
using CryptoPP::SHA1;
using std::cout;
using std::endl;

namespace Utils
{
void PrintDomainParameters(const DL_GroupParameters_EC<ECP>& params);
void PrintPrivateKey(const ECDSA<ECP, SHA1>::PrivateKey& key);
void PrintPublicKey(const ECDSA<ECP, SHA1>::PublicKey& key);

std::string HashString(std::string msg);
} // namespace Utils
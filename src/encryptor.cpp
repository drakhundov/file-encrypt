#include <functional>
#include <cctype>

#include "encryptor.h"

void Encryptor::SetEncryptionFunction(EncryptionFunction func)
{
    this->encrypt_func = func;
}

void Encryptor::SetInputString(const std::string &src)
{
    this->s = src;
}

std::string Encryptor::Encrypt() const
{
    size_t len = this->s.length();
    std::string dest;
    for (size_t i = 0; i < len; i++)
    {
        dest.push_back(this->encrypt_func(this->s[i]));
    }
    return dest;
}

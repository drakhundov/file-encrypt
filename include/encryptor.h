#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <functional>
#include <string>
#include <cctype>

using EncryptionFunction = std::function<char(const char &)>;

class Encryptor
{
public:
    void SetEncryptionFunction(EncryptionFunction);
    void SetInputString(const std::string &);
    std::string Encrypt() const;

private:
    EncryptionFunction encrypt_func;
    std::string s;
};

template <int Shift>
char CaesarCipher(char c)
{
    if (std::isalpha(c))
    {
        char base = std::islower(c) ? 'a' : 'A';
        return (c - base + Shift) % 26 + base;
    }
    return c;
}

#endif

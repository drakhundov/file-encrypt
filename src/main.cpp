#include <iostream>
#include <fstream>
#include "encryptor.h"

void printUsg(const char *);

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printUsg(argv[0]);
        exit(1);
    }
    char option = argv[1][1];
    const char *input_flnm = argv[2];
    const char *output_flnm = argv[3];
    if (option == 'e')
    {
        std::ifstream input_f(input_flnm);
        if (!input_f)
        {
            std::cerr << "Error opening input file: " << input_flnm << std::endl;
            exit(1);
        }
        std::ofstream output_f(output_flnm);
        if (!output_f)
        {
            std::cerr << "Error opening output file: " << output_flnm << std::endl;
            exit(1);
        }
        std::string content((std::istreambuf_iterator<char>(input_f)), std::istreambuf_iterator<char>());
        Encryptor e;
        e.SetEncryptionFunction([](char c)
                                { return CaesarCipher<5>(c); });
        e.SetInputString(content);
        output_f << e.Encrypt();
        input_f.close();
        output_f.close();
        std::cout << "Encryption finished." << std::endl;
    }
    return 0;
}

void printUsg(const char *prog)
{
    std::cerr << "usage: " << prog << " [-e | -d] [--key K] <input_file> <output_file>" << std::endl;
    std::cerr << "\t-e\t\tencrypt" << std::endl;
    std::cerr << "\t-d\t\tdecrypt" << std::endl;                              // TODO
    std::cerr << "\t--key k\t\tuse k as key for caesars cipher" << std::endl; // TODO
}

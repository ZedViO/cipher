//
// Created by Денис on 20.11.2022.
//
#include "header.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 5 && argc != 4) {
        cout << "Error. Use arguments: 'mode = encrypt/decrypt, key ( num > 0 ), filename, text'" << endl;
    } else {
        string mode = argv[1];
        string fname = argv[3];
        int key = atoi(argv[2]);
        string line = argv[4];
        if (mode == "encrypt") {
            vector<unsigned char> ascii(line.size());
            for (size_t i = 0; i < line.size(); ++i) {
                ascii[i] = line[i];
                ascii[i] = ascii[i] << 3 | ascii[i] >> 5;
            }
            opXor(ascii, key);
            std::ofstream file;

            file.open(fname, std::ios::binary);
            for (auto encr: ascii) {
                char toWrite = static_cast<char>(encr);
                file.write(&toWrite, sizeof(encr));
            }
            file << endl;
            file.close();
            cout << "Shaitan srabotal" << endl;
        } else if (mode == "decrypt") {
            ifstream file;
            vector<unsigned char> ascii(line.size());
            file.open(fname, std::ios::binary);
            vector<char> data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            file.close();
            for (size_t j = 0; j < line.size(); ++j) {
                ascii[j] = static_cast<unsigned char>(data[j]);
            }
            opXor(ascii, key);

            for (size_t j = 0; j < ascii.size(); ++j) {
                ascii[j] = ascii[j] << 5 | ascii[j] >> 3;
                std::cout << ascii[j];
            }
        }
    }
return 0;
}

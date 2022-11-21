//
// Created by Денис on 20.11.2022.
//
#include "header.hpp"

void opXor(vector<unsigned char>& ascii, int key) {
    srand(key);
    for (size_t i = 0; i < ascii.size(); ++i){
        unsigned int gamma = rand() & 255;
        unsigned int xored = (static_cast<unsigned int>(ascii[i]) ^ gamma) & 255;
        ascii[i] = xored;
    }
    for (size_t j = 0; j < ascii.size(); ++j){
        ascii[j] = static_cast<unsigned char>(ascii[j]);
    }
}

#pragma once

#define XORLIB_INLINE inline

#include <iostream>
#include <string>

char key = 'd';
namespace xorlib {
    XORLIB_INLINE char* encrypt(const char* plaintext) {
        char* result = new char[strlen(plaintext)+1];
        for (unsigned short i = 0;i <= strlen(plaintext);++i) {
            char cipher = plaintext[i] ^ key;
            result[i] = cipher;
        }
        return result;
    }
}
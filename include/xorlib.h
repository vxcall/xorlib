#pragma once

#define XORLIB_INLINE inline

#include <iostream>
#include <string>
#include <string_view>

char key = 'd';
namespace xorlib {
    XORLIB_INLINE std::string encrypt(const char* plaintext) {
        char* buffer = new char[strlen(plaintext)+1];
        for (unsigned short i = 0;i <= strlen(plaintext);++i) {
            char cipher = plaintext[i] ^ key;
            buffer[i] = cipher;
        }
        buffer += '\0';
        std::string result(buffer);
        delete [] buffer;

        return result;
    }
}
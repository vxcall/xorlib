#pragma once

#define XORLIB_INLINE inline

#include <iostream>

namespace xorlib {
    XORLIB_INLINE void encrypt() {
        std::cout << "xorlib initial commit!" << std::endl;
        return;
    }
}
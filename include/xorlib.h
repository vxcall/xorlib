#pragma once
#include <iostream>
#include <array>

// Every functions must be inlined to avoid ODR violation
#define XORLIB_FORCEINLINE __forceinline

template<size_t N>
class Xorlib {
    char key = 'k';
    [[nodiscard]] constexpr char xoring(char c) const
    {
        return c ^ key;
    }
public:
    // Can't be a std::vector because std::vector allocates memory at runtime.
    // Also can't be a char[N+1] because there's no good way to return char array from decrypt() function.
    std::array<char, N+1> encrypted;

    template<size_t... Seq>
    XORLIB_FORCEINLINE constexpr Xorlib(const char* str, std::index_sequence<Seq...>) : encrypted{ xoring(str[Seq])...}{
        encrypted[N] = '\0';
    };

    XORLIB_FORCEINLINE char* decrypt()
    {
        for (size_t i = 0; i < N; ++i) {
            encrypted[i] = xoring(encrypted[i]);
        }
        return encrypted.data();
    }
};

// A neat macro to use this easily
#define _(s) []{constexpr Xorlib<sizeof(s) - 1> xorlib(s, std::make_index_sequence<sizeof(s) - 1>()); return xorlib;}().decrypt()
#pragma once
#include <string>
#include <cstdint>
#include <cstring>

// Older libstdc++ supplied generic character traits. Ogre UTFString stores
// uint16/uint32 code units; libc++ now requires explicit traits for these types.
template<class C> struct OgreLegacyCharTraits {
    typedef C char_type;
    typedef uint64_t int_type;
    typedef std::streamoff off_type;
    typedef std::streampos pos_type;
    typedef std::mbstate_t state_type;
    static void assign(C& a, const C& b) { a = b; }
    static bool eq(C a, C b) { return a == b; }
    static bool lt(C a, C b) { return a < b; }
    static int compare(const C* a, const C* b, size_t n) {
        for (size_t i = 0; i < n; ++i) {
            if (a[i] < b[i]) return -1;
            if (a[i] > b[i]) return 1;
        }
        return 0;
    }
    static size_t length(const C* s) { size_t n = 0; while (s[n]) ++n; return n; }
    static const C* find(const C* s, size_t n, const C& c) {
        for (size_t i = 0; i < n; ++i) if (s[i] == c) return s + i;
        return 0;
    }
    static C* move(C* d, const C* s, size_t n) { return static_cast<C*>(memmove(d, s, n * sizeof(C))); }
    static C* copy(C* d, const C* s, size_t n) { return static_cast<C*>(memcpy(d, s, n * sizeof(C))); }
    static C* assign(C* d, size_t n, C c) { for (size_t i = 0; i < n; ++i) d[i] = c; return d; }
    static int_type to_int_type(C c) { return c; }
    static C to_char_type(int_type c) { return static_cast<C>(c); }
    static bool eq_int_type(int_type a, int_type b) { return a == b; }
    static int_type eof() { return UINT64_MAX; }
    static int_type not_eof(int_type c) { return c == eof() ? 0 : c; }
};
namespace std {
template<> struct char_traits<unsigned short> : OgreLegacyCharTraits<unsigned short> {};
template<> struct char_traits<unsigned int> : OgreLegacyCharTraits<unsigned int> {};
}

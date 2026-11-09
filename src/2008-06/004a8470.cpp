// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_hintvectoriteratord1f6d4136f577a1f.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
extern "C" void (__cdecl * const invalid_parameter_noinfo)();

struct Empty {
    Empty();
};

struct Empty2 {
    Empty2();
};

inline Empty::Empty() {}
inline Empty2::Empty2() {}

typedef std::vector<unsigned> Vector;
typedef Vector::iterator Iterator;
extern Vector* __cdecl getValues();

struct Base {
    unsigned storage[7];
    unsigned count;
    unsigned bits;
struct BothEmpty : Empty, Empty2 { BothEmpty() {} };


    Base(const Empty&, const Empty2&);
    ~Base();
    unsigned* lookup(const unsigned*);
};

struct S : Base {
    S();
};

S::S() : Base(BothEmpty(), BothEmpty())
{
    Iterator current = getValues()->begin();
    Iterator end = getValues()->end();
    for (; !(current == end); ++current) {
        unsigned key = *current;
        unsigned value = count;
        *lookup(&key) = value;

        unsigned n = count;
        unsigned result = ~0u;
        while (n > 0) {
            n >>= 1;
            ++result;
        }
        bits = result + 1;
    }
}

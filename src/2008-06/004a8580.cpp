// from server: 100% by colin
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
extern void __cdecl ensureInitialized(void (__cdecl*)(), unsigned*);
extern void __cdecl initializeRegistry();
extern unsigned registryGuard;

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
    ensureInitialized(initializeRegistry, &registryGuard);
    Iterator current = getValues()->begin();
    ensureInitialized(initializeRegistry, &registryGuard);
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

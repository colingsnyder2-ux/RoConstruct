// from server: 100% by EspClaude
// from server: 98% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_d8b4d2018e99dd75.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>
typedef boost::detail::shared_count Ref;

struct Pair {
    void* pointer;
    Ref reference;
};

Pair __cdecl acquire(void*);
extern char property[];

struct S {
    char padding[0x3fc];
    void* pointer;
    Ref reference;
    void* get() const { return pointer; }
    void notify(const char*);
    void assign(const Pair&);
    void set(void*);
};

__forceinline void S::assign(const Pair& value)
{
    pointer = value.pointer;
    reference = value.reference;
}

void S::set(void* value)
{
    if (value != get()) {
        assign(acquire(value));
        notify(property);
    }
}

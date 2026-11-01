// from server: 96% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_1506fc53aaadd433.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>
typedef boost::detail::shared_count Ref;

struct Pair {
    void* pointer;
    Ref reference;
};

Pair __cdecl acquire(void*);
extern char property[];
void visitor(void*, void*);
struct Func { void (*fn)(void*, void*); void* arg; Func(void (*f)(void*, void*), void* a) : fn(f), arg(a) {} };

struct S {
    char padding[0x228];
    void* pointer;
    Ref reference;
    void* get() const { return pointer; }
    void notify(const char*);
    void visit(const Func&);
    void assign(const Pair&);
    __forceinline void setRef(void* v) { assign(acquire(v)); }
    __forceinline void visitWith(void (*f)(void*, void*), void* a) { Func t(f, a); visit(t); }
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
        setRef(value);
        notify(property);
        if (value)
            visitWith(&visitor, value);
    }
}

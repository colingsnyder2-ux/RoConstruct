// from server: 100% by EspClaude
// from server: 91% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_2ea5587fc0178957.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct S;

struct Object {
    void attach(S*);
};

typedef boost::shared_ptr<Object> Pointer;

struct Provider {
    Pointer get();
};

extern Pointer __cdecl resolve(void*);
extern Pointer __cdecl convert(const Pointer&) throw();

struct S {
    unsigned char prefix[0x48];
    S* parent;
    unsigned char middle[0x1dc];
    S* context;
    unsigned int reserved;
    Provider* provider;

    bool contains(S*);
    void* lookup();
    void set(Object*);
    void update();
};

void S::update() {
    if (context) {
        S* p = context->parent;
        if (p == this || contains(p))
            return;
    }

    Pointer result = resolve(lookup());
    if (!result.get()) {
        Provider* pr = provider;
        result = convert(pr->get());
        result.get()->attach(this);
    }
    set(result.get());
}



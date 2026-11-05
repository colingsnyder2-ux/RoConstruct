// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_documentguard_b083add24f725b2a.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;
struct Guard {
    unsigned char storage[12];
    Guard(Shared);
    ~Guard();
};

struct Item {
    virtual void unused();
    virtual ~Item();
};

typedef std::vector<Item*> Vector;
struct Owned {
    ~Owned();
};

struct Source {
    virtual void unused0();
    virtual void unused1();
    virtual unsigned long __stdcall release();
    void cleanup();
};

struct Result:Shared {};
struct S {
    unsigned char padding[0x78];
    Vector items;
    Owned* owned;
    Source* source;
    Result get();
    void finish();
    void f();
};

extern S* current_document;
extern void __cdecl set_document(int, S*);

void S::f() {
    {
        Guard guard(get());

        Vector::iterator i=items.begin();
        Vector::iterator last=items.end();
        for(;i!=last;++i)delete *i;
        items.erase(items.begin(),items.end());
        Owned* old=owned;owned=0;delete old;
    }

    if (source) {
        source->cleanup();
        source->release();
        source = 0;
    }

    if (current_document == this)
        set_document(1, this);

    finish();
}
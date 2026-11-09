// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_enumreusedargument9d1d6d3164067894.cpp

// Candidate translation unit (score above; library headers required).
// from server: 85% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern const char enumToken[];

struct Base {
    unsigned int name;
    unsigned int data[2];

    Base(unsigned int, unsigned int, const char*);
    virtual ~Base();
};

#include <vector>
typedef std::vector<unsigned> Storage;
struct Descriptor;
union Argument {unsigned value;Descriptor*object;};

struct Registry {
    void insert(Descriptor**);
};

struct Lookup {
    Descriptor*& find(unsigned int*);
};

Registry* __cdecl getRegistry();
Lookup* __cdecl getLookup();

struct Descriptor : Base {
    Storage values;
    unsigned int extra;
    unsigned int count;

    Descriptor(unsigned int, Argument);
    virtual ~Descriptor();
};

Descriptor::Descriptor(unsigned int a, Argument b)
    : Base(a, b.value, enumToken), values(), extra(0), count(0)
{
    b.object = this;
    getRegistry()->insert(&b.object);
    b.value = name;
    getLookup()->find(&b.value) = this;
}

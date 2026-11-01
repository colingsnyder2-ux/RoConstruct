// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 85% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern const char enumToken[];
extern int enumCount;

struct Base {
    unsigned int name;
    unsigned int data[3];

    Base(unsigned int, const char*, unsigned int, int, int);
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
    : Base(a, enumToken, b.value, 0, 0), values(), extra(0), count(0)
{
    b.object = this;
    getRegistry()->insert(&b.object);
    b.value = name;
    getLookup()->find(&b.value) = this;
    ++enumCount;
}

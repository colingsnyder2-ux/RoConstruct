// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
void* __cdecl lookup(void*, int);

struct Base {
    virtual void dispatch();
    char storage[32];

    Base(std::string, int);
    ~Base();
};

struct S : Base {
    void* selection;

    virtual void dispatch();
    S(const std::string&, int, void*);
};

S::S(const std::string& name, int kind, void* source)
    : Base(name, kind)
{
    selection = lookup(source, -1);
}

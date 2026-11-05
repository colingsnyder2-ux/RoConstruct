// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_historymap_7ba897e3a40a4f16.cpp

// Candidate translation unit (score above; library headers required).
#include <map>

struct Ref {
    void* value;
    Ref& operator=(const Ref&);
};

typedef std::map<int,int> Tree;
struct S {
    unsigned int a;
    unsigned int b;
    Ref c;
    unsigned int d;
    unsigned int e;
    Ref f;
    Tree tree;

    S& operator=(const S&);
};

S& S::operator=(const S& other)
{
    a = other.a;
    b = other.b;
    c = other.c;
    d = other.d;
    e = other.e;
    f = other.f;

    tree=other.tree;
    return *this;
}
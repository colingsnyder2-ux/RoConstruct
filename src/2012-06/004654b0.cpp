// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <memory>

struct GetSetBase {
    virtual void get() const = 0;
};

// operator new(0x10): vptr + a scalar (object/getter) + an 8-byte pair copied by reference.
struct Pair { int b, c; };
struct GetSetImpl : GetSetBase {
    int a;
    Pair bc;
    GetSetImpl(int a_, const Pair& p) : a(a_), bc(p) {}
    virtual void get() const;
};

std::auto_ptr<GetSetBase> makeGetSet(int a, Pair bc)
{
    return std::auto_ptr<GetSetBase>(new GetSetImpl(a, bc));
}
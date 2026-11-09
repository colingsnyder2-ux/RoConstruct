// from server: 97% by tajop
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <memory>

struct GetSetBase {
    virtual void get() const = 0;
};

// operator new(0x10): vptr + a 12-byte by-value argument (stack +8..+0x10).
struct Accessors { int a, b, c; };
struct GetSetImpl : GetSetBase {
    Accessors acc;
    explicit GetSetImpl(const Accessors& a) : acc(a) {}
    virtual void get() const;
};

std::auto_ptr<GetSetBase> makeGetSet(Accessors acc)
{
    return std::auto_ptr<GetSetBase>(new GetSetImpl(acc));
}
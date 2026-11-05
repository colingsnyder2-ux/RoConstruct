// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Base {
    Base(int, int, std::string);
    virtual void execute();
};

struct CutVerb : Base {
    CutVerb(int, int, std::string);
    virtual void execute();
};

CutVerb::CutVerb(int a, int b, std::string name)
    : Base(a, b, name)
{
}

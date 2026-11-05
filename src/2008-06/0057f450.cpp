// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Base {
    Base(std::string, int);
    virtual ~Base();
};
struct S : Base {
    S(std::string, int);
    virtual ~S();
};
S::S(std::string text, int value) : Base(text, value) {}

// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <memory>
struct B { virtual void get() const = 0; };
struct Acc { int a, b, c; };
struct I : B { int pad; Acc acc; int tail; I(const Acc& x) : acc(x) {} virtual void get() const; };
std::auto_ptr<B> mk(Acc x) { return std::auto_ptr<B>(new I(x)); }
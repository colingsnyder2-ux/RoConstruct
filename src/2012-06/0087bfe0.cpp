// from server: 87% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B1 { virtual void a(); };
struct B2 { virtual void b(); };
struct X : B1, B2 { void m(const int& a, const std::string& s); };
struct Binder { X* obj; void (X::*pmf)(const int&, const std::string&); };
void invoke(Binder* b, int a, std::string s) { (b->obj->*(b->pmf))(a, s); }

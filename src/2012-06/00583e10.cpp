// from server: 87% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B1 { virtual void a(); };
struct B2 { virtual void b(); };
struct X : B1, B2 { void m(const std::string& s, const int& a); };
struct Binder { X* obj; void (X::*pmf)(const std::string&, const int&); };
void invoke(Binder* b, std::string s, int a) { (b->obj->*(b->pmf))(s, a); }

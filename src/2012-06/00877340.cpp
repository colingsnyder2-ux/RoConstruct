// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Cb { virtual void call(int a, std::string s); };
struct Obj { char pad[8]; Cb cb; int pad2; int flag; };
void f(Obj* o, int a, std::string s) { if (o->flag) o->cb.call(a, s); }

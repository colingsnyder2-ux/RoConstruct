// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct B { char p[0x98]; ~B(); };
struct M { char q[0x84]; ~M(); };
struct C : B { M m; std::string s; ~C(); };
C::~C() {}

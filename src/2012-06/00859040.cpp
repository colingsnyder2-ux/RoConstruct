// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
#include <new>
struct B{ virtual ~B(); char p[0x24]; B(int); }; struct D:B{ int x; D(int b,int a):B(a){ x=b; } virtual ~D(); }; D* k(void*m,int a,int b){return new(m) D(a,b);}

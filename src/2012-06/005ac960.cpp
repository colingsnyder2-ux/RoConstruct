// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V{ float x,y,z; };
struct B{ V g(int); };
struct S{ char p[0x18]; B b; void f(int); };
void S::f(int a){ b.g(a); }

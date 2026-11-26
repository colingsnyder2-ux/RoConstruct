// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base{ void g(int); };
struct S : Base { char p[0x17c - sizeof(Base)]; int x; void f(int); };
void S::f(int a){ if(!a) x = -1; Base::g(a); }

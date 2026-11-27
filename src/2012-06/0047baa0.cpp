// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct W { bool f1(); void f2(); };
struct X { char pad[0xbc]; W* w; };
struct Y { char pad[0xc]; X* x; void run(int); };
void Y::run(int){ if (x->w->f1()) x->w->f2(); }

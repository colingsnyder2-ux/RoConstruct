// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ void b(); };
struct S{ char p[0x170]; B* q; void a(); void f(); };
void S::f(){ a(); q->b(); }

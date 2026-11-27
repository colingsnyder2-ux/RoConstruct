// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T{ void g(double); }; struct S{ char pad[0x10]; T t; void m(double d); };
void S::m(double d){ t.g(d); }

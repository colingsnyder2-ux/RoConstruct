// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ short p; short a; char pad[0xc]; short b; void m(const S* o); };
void S::m(const S* o){ a=o->a; b=o->b; }

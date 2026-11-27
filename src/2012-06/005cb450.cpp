// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Q{ void g(void*); }; struct R{ char pad[0xac4]; Q* q; }; struct S{ char pad[0x1c]; R* r; void m(); };
void S::m(){ S* t=this; r->q->g(&t); }

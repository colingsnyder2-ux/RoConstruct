// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Sub{ virtual void f(); }; struct P{ char pad[0x1c4]; int x; }; struct S{ char pad[0x1c]; P* p; void m(); };
void S::m(){ ((Sub*)&p->x)->f(); }

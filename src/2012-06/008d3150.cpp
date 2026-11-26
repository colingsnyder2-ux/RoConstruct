// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void __cdecl g(void*); struct A{ char p[0xc]; void* q; void f(); };
void A::f(){ if(q) g(q); }

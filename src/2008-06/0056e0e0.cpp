// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{virtual void v0();; virtual void v1();; virtual void v2(); virtual void m(void*,void*);}; struct S{char pad[0x18]; B* p; bool f(void*,void*);};
bool S::f(void* a,void* b){p->m(a,b); return true;}

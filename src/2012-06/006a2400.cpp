// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
void g(void*,int,int); struct S{char pad[0x88]; void* p; void f();}; void S::f(){ if(p) g(p,2,0); }

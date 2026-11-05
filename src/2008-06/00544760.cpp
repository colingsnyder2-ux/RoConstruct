// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
#pragma optimize("g", off)
struct B{void f();}; struct S{char pad[0x14]; B b; void g();};
void S::g(){b.f();}

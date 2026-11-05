// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#pragma optimize("g", off)
struct B{void f();}; struct S{char pad[0xc]; B b; void g();};
void S::g(){b.f();}

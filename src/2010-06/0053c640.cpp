// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{void f(void*);}; struct S{char pad[0xc]; B* p; void* g(void*);};
void* S::g(void* x){p->f(x);return x;}

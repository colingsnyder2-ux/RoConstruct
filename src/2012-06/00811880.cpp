// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T{void m(int);}; struct S{char pad[0xa8]; void* p; void f();};
void S::f(){((T*)((char*)p+0xcc))->m(0);}

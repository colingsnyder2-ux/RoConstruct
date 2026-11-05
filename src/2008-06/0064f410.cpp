// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{void sub(void*);}; struct S{void* func(void*);};
void* S::func(void* p){((B*)((char*)this+332))->sub(p); return p;}

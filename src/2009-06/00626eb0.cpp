// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{void get(void*,int);}; struct S{void* f(void*);};
void* S::f(void* p){((B*)((char*)this+296))->get(p,1); return p;}

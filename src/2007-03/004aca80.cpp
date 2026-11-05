// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{void sub(void*);}; struct S{void func();};
void S::func(){((B*)((char*)this+8))->sub((void*)0x1);}

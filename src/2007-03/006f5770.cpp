// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
struct S{void* f(int i);}; void* S::f(int i){if((unsigned)i<=0x25)return *(void**)((char*)this+i*4+4); return 0;}

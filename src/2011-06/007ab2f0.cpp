// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x14]; bool f();};
bool S::f(){return *(int*)((char*)this+0x14)==27;}

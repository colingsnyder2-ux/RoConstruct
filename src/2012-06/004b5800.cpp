// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void* memset(void*,int,unsigned); struct S{char pad[0x20]; int a; char pad2[4]; int b; void f();}; void S::f(){ memset(this,0,0x48); b=1; a=1; }

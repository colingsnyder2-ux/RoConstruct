// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x878]; unsigned a; char pad2[0x114]; int b; bool f();}; bool S::f(){ if(a>0) return true; return b!=0; }

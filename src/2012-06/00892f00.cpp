// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S { char pad[20]; unsigned char f; bool g(); };
 bool S::g(){ return (f & 0x40) || (f & 0x80); }

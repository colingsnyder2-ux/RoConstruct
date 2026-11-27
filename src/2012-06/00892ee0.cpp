// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct S { char pad[0x14]; int fl; int f(); };
int S::f(){ return (fl & 0x100) || (fl & 0x200); }

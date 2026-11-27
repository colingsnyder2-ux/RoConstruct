// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct P{char pad[0x40]; char fl;}; struct S{char pad[0x14]; P* p; char f();}; char S::f(){ return p->fl; }

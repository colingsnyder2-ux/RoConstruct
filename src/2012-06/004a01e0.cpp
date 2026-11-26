// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct N{ char p[0x38]; N* n; N* last(); N* other(); };
N* N::last(){ if(n) return n->other(); return this; }

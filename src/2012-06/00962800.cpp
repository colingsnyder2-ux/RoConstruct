// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Y; struct N{ int p; N* n; Y* last(); Y* other(); };
Y* N::last(){ if(n) return n->other(); return (Y*)((char*)this-8); }

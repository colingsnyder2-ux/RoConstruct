// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Q{ int g(int); }; struct A{ int f(){ return ((Q*)((char*)this-0x134))->g(1)!=0; } }; int k(A*a){return a->f();}

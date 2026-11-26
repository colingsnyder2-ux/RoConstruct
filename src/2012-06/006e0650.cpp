// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct P{int h();}; struct A{P* get();}; struct S{int f();}; int S::f(){ P* p=((A*)((char*)this-200))->get(); if(!p) return 0; return p->h(); }

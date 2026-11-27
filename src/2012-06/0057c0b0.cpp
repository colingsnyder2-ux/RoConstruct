// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct P { int x,y; };
P* __cdecl g(void*);
struct T { int a; int b; P f(); };
P T::f(){ return *g(&b); }

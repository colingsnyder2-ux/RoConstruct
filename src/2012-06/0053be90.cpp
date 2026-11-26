// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void __stdcall log(const char*);
struct P{ char pad[0xe8]; bool b; void f(){ if(b){ b=false; log(""); } } };
void g(P*p){p->f();}

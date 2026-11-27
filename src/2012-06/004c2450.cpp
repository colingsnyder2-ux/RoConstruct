// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V{ virtual void f(); }; struct S{ int a,b; int vv; int pad; int x; };
void g(S* s){ if(s->x) ((V*)&s->vv)->f(); }

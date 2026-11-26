// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct V{float x,y;}; void f(const V* s, V* d){ if(d){ d->x=s->x; d->y=s->y; } }

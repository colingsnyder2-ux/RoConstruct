// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct D { bool a; bool b; int p; int q; };
void f(D* d, int x) { d->b = false; d->p = 0; d->q = x; d->a = true; }
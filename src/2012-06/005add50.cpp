// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct N { N *next; };
struct D { char pad[0x70]; N n; };

static N* prev(N *x){ N *y = x->next; while (y->next != x) y = y->next; return y; }
void unlink(D *p){ N *x = p ? &p->n : 0; N *nx = x->next; prev(x)->next = nx; }

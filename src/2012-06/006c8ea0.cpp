// from server: 91% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct N{N* next;}; struct S{N* head; N* alloc(); void f();}; void S::f(){ N* n=head; if(n){ head=n->next; } else { n=alloc(); } if(n) { n->next=0; } }

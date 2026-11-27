// from server: 44% by Xemicl
// roc-cl: 21022
// roc-flags: /O1 /GS- /EHsc /MD
struct N { int a; N* next; };
void __cdecl del(N*);
struct S { int a,b; N* head; void f(); };
void S::f(){ N* p = head; while (p) { N* n = p->next; del(p); p = n; } }

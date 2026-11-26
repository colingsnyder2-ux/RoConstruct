// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ int x; void (__cdecl *fn)(void*); };
struct S{ int p; B* b; int d; void f(); };
void S::f(){ if(b) b->fn(&d); }

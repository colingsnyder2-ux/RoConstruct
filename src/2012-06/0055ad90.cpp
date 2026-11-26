// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ bool g(); };
struct S{ B* h(); bool f(); };
bool S::f(){ B* p = h(); if(p) return p->g(); return false; }

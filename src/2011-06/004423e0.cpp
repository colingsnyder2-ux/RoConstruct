// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct S{virtual void v0(); virtual void m(); void f(int a0);};
void S::f(int a0){m();}

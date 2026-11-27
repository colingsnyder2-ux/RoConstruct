// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A{ int v; }; struct S{ char p[0xc]; void (__thiscall *fn)(char*,A,int); char* obj; void f(A a,int b); }; void S::f(A a,int b){ fn(obj,a,b); }

// from server: 52% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S; struct T{ void g(S*); }; struct S{ char p[0x14]; T** a; T*& at(int i){return a[i];} void f(int i); }; void S::f(int i){ at(i)->g(this); }

// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct S{ char p[0x14]; char b; void f(); };
void S::f(){ b = 0; }

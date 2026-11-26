// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct S{ char p[0xa8]; char x; char* f(); };
char* S::f(){ return &x; }

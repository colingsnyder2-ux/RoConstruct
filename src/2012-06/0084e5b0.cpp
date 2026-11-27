// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T{ void d(); }; struct S{ bool on; char p[0x13]; T t; void f(int); }; void S::f(int){ if(on){ t.d(); on=false; } }

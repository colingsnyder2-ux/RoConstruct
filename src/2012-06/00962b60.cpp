// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{char c;}; void __stdcall h(B); void f(){ B b; b.c=0; h(b); }
// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
int __cdecl h(void*); struct S{ int f(); }; int S::f(){ return h(this)!=0; }
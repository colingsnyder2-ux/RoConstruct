// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void __cdecl h(int*); struct S{ int* p; void f(); }; void S::f(){ if(p) h(p+1); }
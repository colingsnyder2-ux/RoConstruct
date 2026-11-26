// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
int __stdcall g(void*,int,int,void*); struct A{ int f(); };
int A::f(){ return g(this,12,1,(void*)0x750af0); }

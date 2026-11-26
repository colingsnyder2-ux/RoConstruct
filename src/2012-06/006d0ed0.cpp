// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern void fn(); void __stdcall h(void*,int,int,void(*)()); struct S{ void f(); }; void S::f(){ h(this,8,10,fn); }
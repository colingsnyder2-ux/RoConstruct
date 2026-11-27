// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void __stdcall reg(void*); struct Sub{ void m(); }; struct S{ char pad[0x84]; Sub sub; char pad2[0x7b]; bool flag; void f(bool v); }; void S::f(bool v){ if(flag!=v){ flag=v; reg((void*)0xe560d0); sub.m(); } }

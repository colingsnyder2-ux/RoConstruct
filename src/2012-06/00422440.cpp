// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct I{ virtual int __stdcall a(); virtual int __stdcall b(); };
struct In{ int __stdcall f(); };
int In::f(){ I* o = *(I**)((char*)this-8); return o->b(); }

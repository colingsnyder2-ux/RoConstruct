// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct I{ virtual long __stdcall a0(); virtual long __stdcall a1(); virtual long __stdcall a2(); virtual long __stdcall a3(); virtual long __stdcall a4(); virtual long __stdcall a5(); virtual long __stdcall m6(); }; struct X{ char p[0x24]; char c; char q[0x73]; I* i; long f(){ c=0; if(!i) return 0x8004020a; return i->m6(); } }; long k(X*x){return x->f();}

// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
__declspec(dllimport) void* __stdcall A(unsigned); __declspec(dllimport) void __stdcall F(void*); struct I{ virtual void __stdcall a(); virtual void __stdcall b(); virtual void __stdcall Release(); }; struct S{ char pad[0x3c]; I* i; unsigned n; void* p; long f(S* o); }; long __stdcall G(S*,S*); long S::f(S* o){ if(o!=this){ if(n){ F(p); n=0; p=0; } if(i){ i->Release(); i=0; } if(G(this,o)<0) return 0x8007000e; } return 0; }

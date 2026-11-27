// from server: 91% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct IU { virtual long __stdcall Q(); virtual unsigned long __stdcall AddRef(); };
struct Obj { int a; int b; IU* p; long __stdcall f(IU** out); };
long __stdcall g(Obj* o, IU** out);
long __stdcall Obj::f(IU** out){ if (!out) return 0x80004003L; *out = p; IU* q = p; if (q) q->AddRef(); return 0; }

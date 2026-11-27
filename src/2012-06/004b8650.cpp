// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" { __declspec(dllimport) void __stdcall En(void*); __declspec(dllimport) void __stdcall Lv(void*); }
struct S{ char pad[0x50]; int v; int pad2; char cs[24]; int m(); };
int S::m(){ En(cs); int r=v; Lv(cs); return r; }

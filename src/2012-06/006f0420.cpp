// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R { __declspec(dllimport) R(const void*); int x; ~R(); };
struct S { R f() const; };
R S::f() const { R r((const char*)this - 0x84); return r; }

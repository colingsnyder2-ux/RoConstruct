// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R { __declspec(dllimport) R(const char*); int x; ~R(); };
struct S { char pad[0x35]; bool drag; R f() const; };
R S::f() const { R r(drag ? "DragCursor" : "ArrowCursor"); return r; }

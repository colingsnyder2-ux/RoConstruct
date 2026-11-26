// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T6 { short a, b, c; };
struct S { char pad[0x6]; T6 m; T6 f(); };
T6 S::f() { return m; }
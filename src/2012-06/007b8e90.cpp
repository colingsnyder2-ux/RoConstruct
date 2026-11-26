// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V { float x, y, z; };
struct S { const V* g(); V f(int); };
V S::f(int) { return *g(); }
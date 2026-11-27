// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V { int x, y, z; };
bool chk(V*);
struct W { bool f(V v, V* out); };
bool W::f(V v, V* out) { V t = v; if (!chk(&t)) { if (out) *out = t; return true; } return false; }

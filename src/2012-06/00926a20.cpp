// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ void h(); bool f(int); }; bool S::f(int){ h(); return true; }
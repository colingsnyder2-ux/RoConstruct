// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#pragma pack(push,1)
struct V{ int a; short b; };
#pragma pack(pop)
struct S{ V v; V f(); };
V S::f(){ return v; }

// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Str{char d[0x1c]; __declspec(dllimport) Str(const Str&);}; struct TE : Str { char c; int a,b,c2,d2,e,f; TE(const TE& o); }; TE::TE(const TE& o) : Str(o) { c=o.c; a=o.a; b=o.b; c2=o.c2; d2=o.d2; e=o.e; f=o.f; }

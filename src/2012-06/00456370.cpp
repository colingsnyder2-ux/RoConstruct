// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void addref(char*);
struct S { char* p; S(const S& o); };
S::S(const S& o) : p(o.p) { if (p) addref(p + 5); }

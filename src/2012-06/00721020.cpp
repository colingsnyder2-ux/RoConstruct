// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct It { int* node; It(){} };
struct Cont { int pad; int* end; It find(const int& k); };
struct S { char pad[0xa4]; Cont c; bool has(int k); };
bool S::has(int k) { return c.find(k).node != c.end; }

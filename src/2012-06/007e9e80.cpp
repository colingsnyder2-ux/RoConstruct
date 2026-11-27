// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct E { ~E(); int x; };
struct S { E* arr; void set(E* p); };
void S::set(E* p){ E* o = arr; arr = p; delete[] o; }

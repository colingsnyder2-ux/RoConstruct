// from server: 79% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Pt { Pt(); ~Pt(); int x; };
struct M { int d[4]; M(int, int); ~M(); };
struct Root { __declspec(dllimport) Root(); ~Root(); };
struct W : Root { int a; int b; M m; W(int x, int y, int z); };
W::W(int x, int y, int z) : a(0), b(0), m(x, y) {}

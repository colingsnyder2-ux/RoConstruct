// from server: 96% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
bool g;
int fn();
struct M { ~M(); };
struct Base { int a, b; Base() { a = 0; b = 0; } virtual ~Base(); };
struct D : Base { int c; M m; D(); virtual ~D(); };
D::D() { g = true; c = fn(); }

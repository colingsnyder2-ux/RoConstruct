// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_SECURE_SCL=0
#include <vector>
struct T3 { short a, b, c; };
struct V : std::vector<T3> { bool buy(size_t n) { return _Buy(n); } };
bool call(V* v, size_t n) { return v->buy(n); }

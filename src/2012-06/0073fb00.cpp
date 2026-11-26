// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <map>
struct Val { int a, b, c, d; };
std::pair<std::map<int, Val>::iterator, bool> f(std::map<int, Val>& m, const std::pair<const int, Val>& v) { return m.insert(v); }

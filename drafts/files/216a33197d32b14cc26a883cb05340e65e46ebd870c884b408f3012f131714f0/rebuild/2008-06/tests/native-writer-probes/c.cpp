// native-flags: /O2 /EHsc /GS- /MD /DNDEBUG
#include <set>
struct A { std::set<int> s; ~A(); };
void g();
void f() { A a; g(); }

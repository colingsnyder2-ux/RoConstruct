// from server: 100% by EspClaude
#include <set>
struct Obj { Obj(); int pad[4]; };
struct S {
    std::set<int> a;
    std::set<int> b;
    Obj c;
    S();
};
S::S() {}

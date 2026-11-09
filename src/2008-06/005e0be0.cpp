// from server: 100% by tester
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Pair { int a, b; Pair(const Pair& o) : a(o.a), b(o.b) {} };
std::string format(Pair);
struct L {
    char pad[0x268];
    Pair t;
    std::string getTimeStr() const;
};
std::string L::getTimeStr() const { return format(t); }

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <map>
#include <string>

typedef std::vector<int> Block;
struct K1 {}; struct K2 {}; struct K3 {};
struct Holder {
    Block a, b, c;
    std::map<int, int> m0;
    std::map<int, K3> m1;
    std::map<int, K2> m2;
    std::map<int, int> m3, m4;
    ~Holder();
};
Holder::~Holder() {}

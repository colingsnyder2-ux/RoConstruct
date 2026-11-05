// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct S {
    char pad[0x24];
    std::string s;
    int a;
    int b;
    void reset();
};
void S::reset() { s.clear(); a = 0; b = 0; }

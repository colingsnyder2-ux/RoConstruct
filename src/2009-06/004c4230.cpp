// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Named {
    std::string name;
    Named(int unused, std::string n);
};
Named::Named(int unused, std::string n) : name(n) {}

// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Base { char d[0x228]; Base(); ~Base(); };
struct C {
    Base base;
    std::string names[128];
    C();
};
C::C() {}

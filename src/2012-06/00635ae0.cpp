// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct C {
    virtual ~C();
    int pad;
    std::string s1;
    char pad2[0x14];
    std::string s2;
};
C::~C() {}

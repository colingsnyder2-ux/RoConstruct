// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct W { char pad[0xc]; std::string s; };
struct S { char pad[0xc]; W* p; ~S(); };
S::~S() { delete p; }
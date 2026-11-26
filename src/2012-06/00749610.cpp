// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct S { char pad[0xc]; std::string* p; ~S(); };
S::~S() { delete p; }
// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct A { char pad[0x35]; bool opened; std::string f() const; };
std::string A::f() const { return std::string(opened ? "advCursor-openedHand" : "advCursor-default"); }

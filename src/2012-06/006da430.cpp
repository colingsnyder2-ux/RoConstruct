// from server: 87% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Base { int x; std::string a; ~Base(); }; struct C : Base { std::string b; char pad[0x54-0x3c]; bool init; int buf[7]; ~C(); }; C::~C() { if (init) { ((std::string*)buf)->~basic_string(); init = false; } }

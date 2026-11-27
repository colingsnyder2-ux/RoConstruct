// from server: 91% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Base { ~Base(); };
struct R : Base { char pad[0xe10]; std::string names[128]; ~R(); };
R::~R() {}

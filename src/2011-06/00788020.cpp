// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Tool { virtual std::string name() const; };
std::string Tool::name() const { return "UniversalCursor"; }

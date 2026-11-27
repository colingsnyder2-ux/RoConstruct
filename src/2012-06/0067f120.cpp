// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Base { int x; Base(); };
struct Item : Base { std::string name; Item(const char* const* n); void init(); };
Item::Item(const char* const* n) : name(*n) { init(); }

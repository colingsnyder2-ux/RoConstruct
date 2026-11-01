// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace RBX {
class Item;
class X5ed4c0 {
    char pad[0xa4];
    std::vector<Item*> items;
public:
    Item* get(const int& index) const;
};
Item* X5ed4c0::get(const int& index) const
{
    int i = index;
    if (i < 0) return 0; if ((size_t)i >= items.size()) return 0; return items[i];
}
}

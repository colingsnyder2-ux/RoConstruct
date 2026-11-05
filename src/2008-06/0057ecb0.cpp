// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <algorithm>
struct Item {
    char padding[0x194];
    int value;
};
struct Matches {
    int value;
    Matches(int v) : value(v) {}
    bool operator()(const Item* item) const { return item->value != value; }
};
struct S {
    char padding[0x13c];
    std::vector<Item*> items;
    Item* find(int value);
};
Item* S::find(int value)
{
    std::vector<Item*>::iterator it = std::find_if(items.begin(), items.end(), Matches(value));
    if (it != items.end())
        return *it;
    return 0;
}

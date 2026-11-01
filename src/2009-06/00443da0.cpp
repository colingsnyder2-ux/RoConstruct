// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <algorithm>

namespace RBX {
struct Item
{
    char pad[0xc];
    int id;
};

static bool hasId(Item* item, int id)
{
    return item->id == id;
}

struct BoundPred
{
    bool (*f)(Item*, int);
    int id;
    BoundPred(bool (*f)(Item*, int), int id) : f(f), id(id) {}
    bool operator()(Item* p) const { return f(p, id); }
};

class Container
{
    char pad[0x14];
    std::vector<Item*> items;
public:
    bool contains(int id);
};

bool Container::contains(int id)
{
    return std::find_if(items.begin(), items.end(), BoundPred(&hasId, id)) != items.end();
}
}

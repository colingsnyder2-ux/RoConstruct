// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
namespace RBX {
struct Item { virtual ~Item(); };
struct Key {
    int a, b;
    bool operator<(const Key& o) const { return a < o.a; }
};
struct Holder {
    Item* p;
    Holder() : p(0) {}
    Holder(const Holder& o) : p(o.p) {}
    ~Holder() { delete p; }
};
typedef std::map<Key, Holder> ItemMap;
void eraseItem(ItemMap& m, ItemMap::iterator it)
{
    m.erase(it);
}
}

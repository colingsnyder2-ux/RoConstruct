// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
struct Item;
struct Finder { virtual void a(); virtual void b(); virtual int find(int key); };
struct Owner { char pad[0xa4]; std::vector<Item*> items; };
struct S {
    char pad[0x1c];
    Finder* finder;
    Owner* owner;
    Item* get(int key);
};
Item* S::get(int key)
{
    int i = finder->find(key);
    Owner* o = owner;
    if (i < 0) return 0;
    if ((size_t)i >= o->items.size()) return 0;
    return o->items[i];
}

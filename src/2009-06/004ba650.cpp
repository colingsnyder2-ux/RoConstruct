// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct Inner {
    char d[0x2c];
    ~Inner();
};
struct Item {
    int key;
    Inner inner;
    Item(const Item&);
};
class Registry {
public:
    bool add(Item item, void* slot);
};
extern Registry registry;
struct Holder {
    Registry* reg;
    int x;
    int slot;
    void init(Item item);
};
void Holder::init(Item item)
{
    reg = registry.add(item, &slot) ? &registry : 0;
}
}

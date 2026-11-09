// from server: 100% by EspClaude
// roc 2008-06 004cae60  unit: RBX::Network::RoundRobinPhysicsSender  size: 212 bytes
struct Hook {
    Hook* prev;
    Hook* next;
};

struct ItemBase {
    char pad[8];
    double val;
    char pad2[0x50];
};

struct Item : ItemBase, Hook {};

extern void __cdecl decrement(Hook** it);
extern void __cdecl increment(Hook** it);

struct Pad12 {
    void* a;
    Item* container;
    void* b;
};

struct Sender {
    void* s;
    bool compare(Item* key, Item* item, Item* unused);
};

struct Outer : Pad12, Sender {};

bool Sender::compare(Item* key, Item* item, Item*)
{
    Hook* h;
    if (item != static_cast<Item*>(static_cast<Outer*>(this)->container->next)) {
        h = item;
        decrement(&h);
        if (key->val > static_cast<Item*>(h)->val)
            return false;
    }
    h = item;
    increment(&h);
    Item* n = static_cast<Item*>(h);
    return n == static_cast<Outer*>(this)->container || !(n->val > key->val);
}

// from server: 100% by king_originala
struct S;
struct Node;

struct Tree {
    char padding[0x18];
    Node* end;
};

struct Node {
    char padding[0x10];
    void* value;
};

struct Iterator {
    Tree** owner;
    Node* node;
};

struct Map {
    Iterator* find(Iterator* result, const S* key);
};

struct Registry {
    char padding[0x30];
    Map map;
};

extern Registry* __cdecl getRegistry();
extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct S {
    void** f(void** result);
};

void** S::f(void** result)
{
    Iterator storage;
    Iterator* it = getRegistry()->map.find(&storage, this);

    void (__cdecl* invalid)() = invalid_parameter_noinfo;
    if (!it->owner)
        invalid();

    Tree* tree = it->owner ? *it->owner : 0;
    if (it->node == tree->end)
        invalid();

    *result = it->node->value;
    return result;
}

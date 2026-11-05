// from server: 100% by king_originala
struct Node {
    void* unused;
    void* value;
};

struct Map {
    char data[36];
    void** lookup(void* const* key);
};

struct Listener {
    void update(void** node);
};

void* __cdecl getLocalScope();

struct S_func_00451a60 {
    char pad[84];
    Map map;
    Listener listener;
    void f(void* key, void* node);
};

void S_func_00451a60::f(void* key, void* node)
{
    Node* original = static_cast<Node*>(node);
    if (original) {
        listener.update(&node);
        void* value = original->value;
        node = key;
        *map.lookup(&node) = value;
    } else {
        void* value = getLocalScope();
        node = key;
        *map.lookup(&node) = value;
    }
}

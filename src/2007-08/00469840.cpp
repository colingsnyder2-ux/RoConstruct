// from server: 58% by colin
struct LDraw2RobloxColorMap {
    char pad[0x48];
    struct Node {
        char pad0[4];
        Node* parent;
        char pad1[0x20];
        int value;
    };
    Node* head;
    int lookup(int key);
};

extern "C" void __stdcall _invalid_parameter_noinfo();

int LDraw2RobloxColorMap::lookup(int key)
{
    Node* sentinel = (Node*)((char*)this + 0x48);
    Node* result;
    Node* tmp;
    Node* node;
    Node* parent;

    // call 0x5bbd70 - some tree lookup helper
    // signature: (Node** out, int* key, Node* sentinel)
    // We approximate with a local declaration
    extern void __stdcall tree_lookup(Node** out, int* key, Node* sentinel);
    tree_lookup(&result, &key, sentinel);

    node = result;
    parent = sentinel->parent;

    if (node != 0 && node != sentinel) {
        _invalid_parameter_noinfo();
    }

    tmp = result;
    if (tmp != parent) {
        if (node == 0) {
            _invalid_parameter_noinfo();
        }
        if (tmp == node->parent) {
            _invalid_parameter_noinfo();
        }
        return tmp->value;
    }
    return 0;
}

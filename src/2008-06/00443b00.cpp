// from server: 100% by colin
struct Storage;

struct Node {
    Storage* convert();
};

struct Storage {
    Node* find(const char* key);
    Node* lookup(const char* key);
};

struct Link {
    void* reserved;
    const char* key;
};

struct Argument {
    void* reserved0;
    const char* key;
    void* reserved8;
    Link* parent;
};

struct Descriptor {
    char reserved[0x130];
    Storage* storage;
    Node* find(Argument* argument);
};

Node* Storage::lookup(const char* key)
{
    if (this)
        return find(key);
    return 0;
}

Node* Descriptor::find(Argument* argument)
{
    Storage* s = storage;
    Node* node = s ? s->lookup(argument->parent->key + 4) : 0;
    if (node) {
        Storage* next = node->convert();
        if (next) {
            const char* key = argument->key + 4;
            return next->find(key);
        }
    }
    return 0;
}

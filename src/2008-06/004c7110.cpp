// from server: 100% by king_originala
struct Link {
    unsigned int parent;
    Link* left;
    Link* right;
};

struct Node {
    unsigned int reserved[2];
    unsigned int key;
    char padding[0x280 - 12];
    Link link;
};

struct Owner {
    unsigned int reserved;
    Node* head;
};

struct Result {
    int right;
    Link* parent;
};

struct Item {
    bool find(unsigned int key, Result* result, unsigned int unused);
};

bool Item::find(unsigned int key, Result* result, unsigned int unused)
{
    Node* parent =
        (this ? reinterpret_cast<Owner*>(
                    reinterpret_cast<char*>(this) - 12) : 0)->head;

    unsigned int root =
        (this ? reinterpret_cast<Owner*>(
                    reinterpret_cast<char*>(this) - 12) : 0)
            ->head->link.parent & ~1u;

    Node* node = root
        ? reinterpret_cast<Node*>(root - 0x280)
        : 0;

    bool left = true;
    while (node) {
        left = key < node->key;
        parent = node;
        Link* next = left ? node->link.left : node->link.right;
        node = next
            ? reinterpret_cast<Node*>(
                  reinterpret_cast<char*>(next) - 0x280)
            : 0;
    }

    result->right = !left;
    result->parent = parent ? &parent->link : 0;
    return true;
}

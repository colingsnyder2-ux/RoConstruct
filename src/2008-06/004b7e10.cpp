// from server: 100% by king_originala
struct Value {
    char data[24];
    ~Value();
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char padding[8];
    Value value;
    unsigned char color;
    unsigned char nil;
};

extern "C" void __cdecl release(void*);

struct S {
    void erase(Node* node);
};

void S::erase(Node* node)
{
    for (Node* next = node; !next->nil; node = next) {
        erase(next->right);
        next = next->left;
        node->value.~Value();
        release(node);
    }
}

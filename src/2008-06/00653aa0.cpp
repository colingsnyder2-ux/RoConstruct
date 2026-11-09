// from server: 100% by king_originala
struct Value {
    char storage[32];
    ~Value();
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    unsigned long padding;
    Value value;
    unsigned char color;
    unsigned char nil;
};

extern "C" void __cdecl release(void*);

struct S {
    void erase(Node* root);
};

void S::erase(Node* root)
{
    Node* current = root;
    while (!current->nil) {
        erase(current->right);
        current = current->left;
        root->value.~Value();
        release(root);
        root = current;
    }
}

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Key {
    char padding[12];
    int value;
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    Key key;
    char padding[4];
    unsigned char color;
    unsigned char nil;
};

struct S {
    char padding[24];
    Node* head;
    Node* find(const Key* key);
};

Node* S::find(const Key* key)
{
    Node* result = head;
    Node* current = result->parent;
    while (!current->nil) {
        const Key* candidate = &current->key;
        bool less;
        if (candidate->value < key->value)
            less = true;
        else if (candidate->value > key->value)
            less = false;
        else
            less = candidate < key;
        if (less) {
            current = current->right;
        } else {
            result = current;
            current = current->left;
        }
    }
    return result;
}
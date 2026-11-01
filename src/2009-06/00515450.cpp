// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Key {
    int id;
    float a;
    float b;
    int c;
};

inline bool operator<(const Key& l, const Key& r) {
    if (l.id < r.id) return true;
    if (l.id > r.id) return false;
    if (l.a < r.a) return true;
    if (l.a > r.a) return false;
    if (l.b < r.b) return true;
    if (l.b > r.b) return false;
    return l.c < r.c;
}
struct Node {
    Node* left;
    Node* parent;
    Node* right;
    Key key;
    char padding[9];
    unsigned char nil;
};

struct S {
    char padding[24];
    Node* head;

    Node* find(const Key& key);
};

Node* S::find(const Key& key)
{
    Node* node = head->parent;
    Node* result = head;
    if (!node->nil) {
        do {
            if (node->key < key) {
                node = node->right;
            } else {
                result = node;
                node = node->left;
            }
        } while (!node->nil);
    }
    return result;
}

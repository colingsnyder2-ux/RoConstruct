// from server: 100% by king_originala
struct Key {
    int padding[3];
    int value;
    bool operator<(const Key& other) const;
};

inline bool Key::operator<(const Key& other) const
{
    if (this + 1 < &other + 1)
        return true;
    if (this + 1 > &other + 1)
        return false;
    if (value < other.value)
        return true;
    if (value > other.value)
        return false;
    return this < &other;
}

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    Key key;
    unsigned char padding[12];
    unsigned char color;
    unsigned char nil;
};

struct PartChunk {
    unsigned char padding[24];
    Node* head;
    Node* find(const Key* key);
};

Node* PartChunk::find(const Key* key)
{
    Node* result = head;
    Node* node = result->parent;

    while (!node->nil) {
        if (node->key < *key) {
            node = node->right;
        } else {
            result = node;
            node = node->left;
        }
    }

    return result;
}

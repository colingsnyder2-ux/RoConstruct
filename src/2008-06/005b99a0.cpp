// from server: 100% by king_originala
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    int key;
    char reserved[8];
    unsigned char color;
    unsigned char nil;
};

struct Iterator {
    void* owner;
    Node* node;

    bool operator==(const Iterator& other) const;
};

inline bool Iterator::operator==(const Iterator& other) const
{
    if (owner == 0 || owner != other.owner)
        _invalid_parameter_noinfo();
    return node == other.node;
}

struct SoundChannel {
    void* owner;
    char reserved[20];
    Node* head;

    Iterator end();
    Iterator find(const int& key);
};

inline Iterator SoundChannel::end()
{
    Iterator result;
    result.node = head;
    result.owner = owner;
    return result;
}

Iterator SoundChannel::find(const int& key)
{
    Node* current = head->parent;
    Node* candidate = head;

    while (!current->nil) {
        if (current->key < key) {
            current = current->right;
        } else {
            candidate = current;
            current = current->left;
        }
    }

    Iterator found;
    found.node = candidate;
    found.owner = owner;

    return (!(found == end()) && !(key < candidate->key))
        ? found : end();
}

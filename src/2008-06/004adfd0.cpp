// from server: 100% by king_originala
extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    unsigned int key;
    unsigned char padding[45];
    unsigned char nil;
};

struct Iterator {
    void* owner;
    Node* node;

    Iterator(Node*, void*);
    bool operator==(const Iterator&) const;
};

inline Iterator::Iterator(Node* n, void* p) {
    node = n;
    owner = p;
}

inline bool Iterator::operator==(const Iterator& other) const {
    if (!owner || owner != other.owner)
        invalid_parameter_noinfo();
    return node == other.node;
}

struct S {
    void* owner;
    unsigned char padding[20];
    Node* head;

    Iterator end() const;
    Iterator find(const unsigned int&);
};

inline Iterator S::end() const {
    return Iterator(head, owner);
}

Iterator S::find(const unsigned int& key) {
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

    Iterator where(candidate, owner);
    return where == end() || key < candidate->key ? end() : where;
}

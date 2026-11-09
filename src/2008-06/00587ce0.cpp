// from server: 100% by king_originala
extern "C" void (__cdecl *_invalid_parameter_noinfo)();

struct Node {
    Node *left;
    Node *parent;
    Node *right;
    unsigned int key;
    unsigned char reserved[57];
    unsigned char nil;
};

struct Iterator {
    void *owner;
    Node *node;

    Iterator();
    Iterator(void *, Node *);
    bool operator==(const Iterator &) const;
};

inline Iterator::Iterator()
{
}

inline Iterator::Iterator(void *o, Node *n)
{
    node = n;
    owner = o;
}

inline bool Iterator::operator==(const Iterator &other) const
{
    if (!owner || owner != other.owner)
        _invalid_parameter_noinfo();
    return node == other.node;
}

struct S {
    void *owner;
    unsigned char reserved[20];
    Node *head;

    Iterator f(const unsigned int *key);
};

Iterator S::f(const unsigned int *key)
{
    Node *node = head->parent;
    Node *where = head;

    while (!node->nil) {
        if (node->key < *key)
            node = node->right;
        else {
            where = node;
            node = node->left;
        }
    }

    Iterator result(owner, where);
    Iterator finish;
    Iterator *selected;

    if (!(result == Iterator(owner, head)) && *key >= where->key)
        selected = &result;
    else {
        finish.node = head;
        finish.owner = owner;
        selected = &finish;
    }

    return *selected;
}

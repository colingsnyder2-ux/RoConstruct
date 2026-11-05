// from server: 100% by king_originala
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Node
{
    Node* left;
    Node* parent;
    Node* right;
    signed char key;
    unsigned char color;
    unsigned char nil;
};

struct Iterator
{
    void* owner;
    Node* node;

    Iterator(void* o, Node* n);
    bool operator==(const Iterator& other) const;
};

struct S
{
    void* owner;
    unsigned char padding[20];
    Node* head;

    Iterator end() const;
    Iterator f(const signed char& key);
};

inline Iterator::Iterator(void* o, Node* n)
{
    node = n;
    owner = o;
}

inline bool Iterator::operator==(const Iterator& other) const
{
    if (!owner || owner != other.owner)
        _invalid_parameter_noinfo();
    return node == other.node;
}

inline Iterator S::end() const
{
    return Iterator(owner, head);
}

Iterator S::f(const signed char& key)
{
    Node* current = head->parent;
    Node* candidate = head;

    if (!current->nil)
    {
        do
        {
            if (current->key < key)
                current = current->right;
            else
            {
                candidate = current;
                current = current->left;
            }
        } while (!current->nil);
    }

    Iterator position(owner, candidate);
    return position == end() || key < position.node->key
        ? end()
        : position;
}

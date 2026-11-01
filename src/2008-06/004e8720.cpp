// from server: 100% by king_originala
extern "C" void (__cdecl* const invalid_parameter_noinfo)();

struct Key
{
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

struct Node
{
    int padding[3];
    Key key;
};

struct S;

struct Iterator
{
    void* owner;
    Node* node;
    Iterator(Node* n, const S* container);
    bool operator!=(const Iterator& other) const;
};

struct S
{
    void* owner;
    int padding[5];
    Node* head;

    Node* find(const Key& key);
    Iterator end() const;
    Iterator func_004e8720(const Key& key);
};

inline Iterator::Iterator(Node* n, const S* container)
{
    node = n;
    if (!container)
        invalid_parameter_noinfo();
    owner = container->owner;
}

inline bool Iterator::operator!=(const Iterator& other) const
{
    if (!owner || owner != other.owner)
        invalid_parameter_noinfo();
    return node != other.node;
}

inline Iterator S::end() const
{
    return Iterator(head, this);
}

Iterator S::func_004e8720(const Key& key)
{
    Iterator result(find(key), this);
    return result != end() && !(key < result.node->key) ? result : end();
}

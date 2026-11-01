// from server: 100% by Espeon
// from server: 91% by king_originala
struct String
{
    char storage[32];
};

struct Value
{
    unsigned int data[4];
    ~Value();
};

struct Pair
{
    String key;
    Value value;
    Pair(const String &, const Value &);
    ~Pair();
};

struct Node
{
    char links[12];
    String key;
    Value value;
};

struct S;

struct Proxy
{
    S *container;
};

extern __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();
extern bool (__cdecl *string_less)(const String &, const String &);

struct Iterator
{
    Proxy *owner;
    Node *node;

    bool operator==(const Iterator &) const;
    void unpack(Proxy *&, Node *&) const;
};

inline bool Iterator::operator==(const Iterator &other) const
{
    if (!owner || owner != other.owner)
        _invalid_parameter_noinfo();
    return node == other.node;
}

inline void Iterator::unpack(Proxy *&outOwner, Node *&outNode) const
{
    outOwner = owner;
    outNode = node;
}

struct S
{
    Proxy *proxy;
    char padding[20];
    Node *head;

    Node *lower_bound(const String &);
    Iterator insert(Iterator, const Pair &);
    Value &lookup(const String &);
};

Value &S::lookup(const String &key)
{
    Node *node = lower_bound(key);

    if (!this)
        _invalid_parameter_noinfo();

    Proxy *owner = proxy;
    Iterator position = { owner, node };
    Iterator end = { proxy, head };

    if (position == end || string_less(key, node->key))
    {
        Value empty = { 0, 0, 0, 0 };
        insert(position, Pair(key, empty)).unpack(owner, node);
    }

    if (!owner)
        _invalid_parameter_noinfo();
    S *container = owner ? owner->container : 0;

    if (node == container->head)
        _invalid_parameter_noinfo();

    return node->value;
}

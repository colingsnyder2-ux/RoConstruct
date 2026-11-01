// from server: 100% by king_originala
extern "C" int __cdecl sub_5122C0(unsigned int* p);

struct Link
{
    Link* next;
};

struct Node
{
    unsigned int key;
    char padding[0x28C];
    Link link;
};

struct Table
{
    unsigned int bucketCount;
};

struct Result
{
    Node* node;
    Table* owner;

    Result();
    Result(Node*, Table*);
};

inline Result::Result()
{
}

inline Result::Result(Node* n, Table* t)
{
    owner = t;
    node = n;
}

struct S
{
    char padding[8];
    unsigned int bucketCount;
    char reserved[8];
    Link** buckets;

    Result find(unsigned int* key, unsigned int, unsigned int);
};

Result S::find(unsigned int* key, unsigned int, unsigned int)
{
    unsigned int hash = (unsigned int)sub_5122C0(key);
    unsigned int index = hash % bucketCount;
    Table* owner = reinterpret_cast<Table*>(padding + 8);
    Link** bucket = buckets + index;
    Link* current = *bucket;

    while (current != reinterpret_cast<Link*>(bucket))
    {
        Node* node = current
            ? reinterpret_cast<Node*>(reinterpret_cast<char*>(current) - 0x290)
            : 0;

        if (*key == node->key)
        {
            Result result;
            result.owner = owner;
            result.node = current
                ? reinterpret_cast<Node*>(reinterpret_cast<char*>(current) - 0x290)
                : 0;
            return result;
        }

        current = current->next;
    }

    return Result(
        *reinterpret_cast<Node**>(reinterpret_cast<char*>(this) - 8),
        owner);
}

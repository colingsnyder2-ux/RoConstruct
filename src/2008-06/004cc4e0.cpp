// from server: 100% by king_originala
typedef unsigned int UInt;

struct Link {
    Link* next;
};

struct Payload {
    UInt key;
    char padding[108];
};

struct Node : Payload, Link {
};

struct Prefix {
    char padding[12];
};

struct Table {
    char padding0[8];
    UInt bucketCount;
    char padding1[8];
    Link** buckets;
    char padding2[8];
    UInt firstBucket;

    void reserve(UInt count);
    Node* create(const UInt* key, Node* node);
    Node* insert(const UInt* key, Node* node);
};

struct Owner : Prefix, Table {
    UInt count;
};

Node* Table::insert(const UInt* key, Node* node)
{
    reserve(static_cast<Owner*>(this)->count + 1);

    UInt value = *key;
    UInt bucket = ((value >> 3) + value) % bucketCount;
    Link** head = buckets + bucket;
    Link* sentinel = reinterpret_cast<Link*>(head);
    Link* current = *head;

    while (current != sentinel) {
        if (value == static_cast<Node*>(current)->key)
            return static_cast<Node*>(current);
        current = current->next;
    }

    Node* result = create(key, node);
    if (result == node) {
        Link* link = static_cast<Link*>(node);
        link->next = *head;
        *head = link;
        if (firstBucket > bucket)
            firstBucket = bucket;
    }
    return result;
}

// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Node {
    char padding0[16];
    unsigned short bucket;
    char padding1[6];
    unsigned int index;
    char padding2[12];
    Node *next;
};

struct Entry {
    unsigned int value;
    Node *node;
};

struct Bucket {
    char padding[12];
    Entry *begin;
    Entry *end;
    Entry *capacity;
};

struct S {
    char padding0[12];
    Bucket buckets[4];
    char padding1[8];
    Node *freeList;

    void remove(Node *node);
};

void S::remove(Node *node)
{
    unsigned int index = node->index;
    Bucket *bucket = &buckets[node->bucket];

    if (index >= static_cast<unsigned int>(bucket->end - bucket->begin))
        invalid_parameter_noinfo();

    Node **link = &bucket->begin[index].node;
    while (*link != node)
        link = &(*link)->next;

    *link = node->next;
    node->next = freeList;
    freeList = node;
}

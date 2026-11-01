// from server: 100% by king_originala
struct Node {
    unsigned int reserved0;
    Node* next;
    unsigned int reserved1[2];
    unsigned int index;
    unsigned int reserved2[3];
    unsigned short bucket;
};

struct Entry {
    Node* node;
    unsigned int reserved;
};

struct Bucket {
    unsigned int reserved[3];
    Entry* begin;
    Entry* end;
    Entry* capacity;
};

extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct S {
    unsigned int reserved[3];
    Bucket buckets[1];

    void remove(Node* node);
};

void S::remove(Node* node)
{
    unsigned int index = node->index;
    Bucket* bucket = &buckets[node->bucket];

    if (index >= static_cast<unsigned int>(bucket->end - bucket->begin))
        invalid_parameter_noinfo();

    Node** link = &bucket->begin[index].node;
    if (*link != node) {
        do {
            link = &(*link)->next;
        } while (*link != node);
        *link = node->next;
    } else {
        *link = node->next;
    }
}

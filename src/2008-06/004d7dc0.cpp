// from server: 100% by king_originala
extern "C" void __stdcall destroyElement(void *);
extern "C" void __stdcall destroyArray(
    void *, unsigned int, int, void (__stdcall *)(void *));
extern "C" void __cdecl freeNode(void *);
extern "C" void __cdecl alignedFree(void *);

struct Node
{
    char padding[16];
    unsigned int elements[4];
    Node *next;
};

struct S
{
    unsigned int unknown;
    int size;
    Node **buckets;
    int bucketCount;

    void clear();
};

void S::clear()
{
    for (int i = 0; i < bucketCount; ++i)
    {
        Node *node = buckets[i];
        while (node)
        {
            Node *next = node->next;
            destroyArray(node->elements, 4, 4, destroyElement);
            freeNode(node);
            node = next;
        }
    }

    alignedFree(buckets);
    buckets = 0;
    bucketCount = 0;
    size = 0;
}

// from server: 100% by king_originala
extern "C" void __cdecl free_node(void*);
extern "C" void __cdecl aligned_free(void*);
extern "C" void __stdcall destroy_value(void*);
extern "C" void __stdcall destroy_array(
    void*, unsigned int, int, void (__stdcall *)(void*));

struct Node
{
    unsigned char padding[16];
    unsigned int value;
    Node* next;
};

struct S
{
    unsigned int padding;
    int used;
    Node** buckets;
    int count;

    void clear();
};

void S::clear()
{
    for (int i = 0; i < count; ++i)
    {
        Node* node = buckets[i];
        while (node)
        {
            Node* next = node->next;
            destroy_array(&node->value, 4, 1, destroy_value);
            free_node(node);
            node = next;
        }
    }

    aligned_free(buckets);
    buckets = 0;
    count = 0;
    used = 0;
}

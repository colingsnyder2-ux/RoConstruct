// from server: 93% by atomic.potato
struct S
{
    struct Node
    {
        Node *next;
        char pad[0x20];
        void *value;
    };

    char pad[0x10];
    Node *nodes;
    void remove(void *);
};

extern "C" void OgreNodeRemoveAllChildren();

void S::remove(void *value)
{
    Node *head = nodes;
    Node *p = head->next;
    while (p != head)
    {
        remove(p->value);
        p = p->next;
    }
    OgreNodeRemoveAllChildren();
}

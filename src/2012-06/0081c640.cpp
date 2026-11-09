// from server: 66% by atomic.potato
struct S
{
    struct VTable
    {
        int (*f)(void *);
        int (*g)(void *);
    };

    struct Node
    {
        VTable *vtable;
        int unknown;
        Node *next;
        int value;
    };

    Node *member[44];
    int f();
};

int S::f()
{
    Node *node = member[43];
    while (node->vtable->g(node) != 7)
        node = node->next;
    return node->value;
}

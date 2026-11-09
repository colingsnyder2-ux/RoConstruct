// from server: 81% by atomic.potato
struct S
{
    struct Node
    {
        struct VTable
        {
            int (*f0)(Node *);
            int (__thiscall *f1)(Node *);
        };

        VTable *vtable;
        Node *next;
    };

    int unused[54];
    Node *field_d8;
    Node *f();
};

S::Node *S::f()
{
    Node *p = field_d8;

    if (p->vtable->f1(p) == 7)
        return p;

    p = p->next;
    while (p->vtable->f1(p) != 7)
        p = p->next;

    return p;
}

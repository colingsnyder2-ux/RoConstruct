// from server: 87% by atomic.potato
struct S_0081c610
{
    struct VTable
    {
        int (__thiscall *f)(void*);
    };

    struct Node
    {
        VTable* vtable;
        int pad;
        Node* next;
    };

    char pad[172];
    Node* node;

    Node* f();
};

S_0081c610::Node* S_0081c610::f()
{
    Node* p = node;
    while (p->vtable->f(p) != 7)
        p = p->next;
    return p;
}

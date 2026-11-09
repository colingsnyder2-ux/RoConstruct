// from server: 85% by atomic.potato
struct S_func_0081cf60
{
    struct Node
    {
        virtual int f();
        Node* next;
        char pad[40];
        int value;
    };

    char pad[172];
    Node* m_p;
    int f();
};

int S_func_0081cf60::f()
{
    Node* p = m_p;
    while (p->f() != 5)
        p = p->next;
    return p->value == 0;
}

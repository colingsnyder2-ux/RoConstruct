// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S_func_0081cf60
{
    struct Node
    {
        virtual void f0();
        virtual int f();
        int x;
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
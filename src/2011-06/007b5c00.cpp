// from server: 56% by atomic.potato
struct TreeStage
{
    struct Node
    {
        Node *next;
        Node *prev;
    };

    Node head;
    int f(int);
};

int __thiscall TreeStage::f(int)
{
    Node *end = &head;
    Node *p = head.next;

    while (p != end)
    {
        Node *next = p->next;
        p->next = 0;
        p->prev = 0;
        p = next;
    }

    end->next = end;
    end->prev = end;
    head.next = 0;
    return 0;
}

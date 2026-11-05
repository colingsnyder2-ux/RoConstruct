// from server: 91% by atomic.potato
struct S
{
    int count;
    struct Node
    {
        Node *next;
        Node *prev;
    };

    Node node;
    void f(Node *value);
};

void S::f(Node *value)
{
    Node *p = value ? value + 1 : 0;
    Node *head = &node;
    Node *next = head->next;

    p->prev = next;
    next->next = p;
    head->next = p;
    p->next = head;
    ++count;
}

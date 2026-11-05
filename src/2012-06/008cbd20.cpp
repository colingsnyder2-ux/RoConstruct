// from server: 65% by atomic.potato
struct S
{
    void f(int);
};

void __thiscall S::f(int)
{
    struct Node
    {
        Node* next;
        int value;
        void (__thiscall *action)(Node*);
    };

    Node* head = *(Node**)((char*)this + 0x10);
    Node* node = head->next;

    while (node != head)
    {
        node->action(node);
        node = node->next;
    }
}

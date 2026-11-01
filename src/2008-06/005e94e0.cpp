// from server: 100% by king_originala
struct Node {
    virtual void slot0();
    virtual int kind();
    int reserved;
    Node* next;
    void apply(void* argument);
};

struct S {
    char padding[0x88];
    Node* node;
    void f(void* argument);
};

void S::f(void* argument)
{
    Node* current = node;
    while (current->kind() != 2)
        current = current->next;
    current->apply(argument);
}

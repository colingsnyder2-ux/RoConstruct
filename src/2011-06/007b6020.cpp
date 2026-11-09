// from server: 94% by atomic.potato
struct Node {
    Node* next;
    Node* prev;
    char pad[0x20];
    virtual void method(double);
};

struct List {
    char pad[0x14];
    Node* head;
    void iterate(double);
};

void List::iterate(double value) {
    Node* node = head;
    Node* sentinel = (Node*)((char*)this + 0x14);
    while (node != sentinel) {
        Node* n = node;
        if (n != 0) {
            n = (Node*)((char*)n - 0x28);
        } else {
            n = 0;
        }
        n->method(value);
        node = node->next;
    }
}

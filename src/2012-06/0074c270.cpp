// from server: 37% by atomic.potato
struct Node {
    char pad0[4];
    Node* next;
};

struct List {
    char pad0[4];
    Node* head;
    int count;
    void splice(List* other, int n, int a, int b, int c, int d);
};

extern "C" void __stdcall sub_749a00(Node* pos, int n);

void List::splice(List* other, int n, int a, int b, int c, int d)
{
    if (this != other) {
        sub_749a00(other->head, n);
        other->count -= n;
    }
    Node* x = other->head;
    Node* y = this->head;
    Node* z = x->next;
    y->next = z;
    x->next = y;
    this->head = x;
    other->head = z;
}

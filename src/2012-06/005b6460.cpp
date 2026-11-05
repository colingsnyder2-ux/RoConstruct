// from server: 16% by atomic.potato
// roc 2012-06 005b6460  unit: RBX::Network::DirectPhysicsReceiver  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005b6460

struct Node {
    Node* next;
    Node* prev;
};

struct List {
    Node* head;
};

struct S {
    char pad[8];
    List* list;
    bool f(List* other, int, int);
};

bool S::f(List* other, int, int) {
    Node* n = other->head;
    Node* first = n;
    if (n == first) {
        return true;
    }
    while (true) {
        Node* cur = other->head;
        Node* base;
        if (n != 0) {
            base = (Node*)((char*)n - 0x30);
        } else {
            base = 0;
        }
        if (cur == base->next) {
            other->head = n;
            return false;
        }
        n = n->next;
        if (n == other->head) {
            return true;
        }
    }
}

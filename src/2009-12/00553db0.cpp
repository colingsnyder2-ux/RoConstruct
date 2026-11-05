// from server: 25% by atomic.potato
extern "C" void* __stdcall sub_B20210(unsigned int);

struct Node {
    char pad0[4];
    int refcount;
    Node* prev;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
    int count;
    int field_c;
    bool insert(Node* n);
};

bool List::insert(Node* n) {
    if (count <= 0) {
        head = (Node*)sub_B20210(0x14);
        if (head == 0) {
            return false;
        }
        count = 1;
        if (!insert(head)) {
            return false;
        }
        head->refcount--;
        Node* h = head;
        return h->prev->refcount != 0;
    }
    Node* h = head;
    h->refcount--;
    Node* old = h->prev;
    if (h->refcount != 0) {
        return old->refcount != 0;
    }
    count--;
    head = h->next;
    h->next->prev = h->prev;
    h->prev->next = h->next;
    int c = field_c;
    field_c = c + 1;
    if (c == 0) {
        tail = h;
        h->prev = h;
        h->next = h;
        return true;
    }
    h->prev = tail;
    h->next = tail->next;
    tail->next->prev = h;
    tail->next = h;
    return true;
}

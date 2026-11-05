// from server: 67% by atomic.potato
struct Node {
    Node* next;
    Node* prev;
    void* vtable;
    char pad[4];
};

struct List {
    char pad0[4];
    Node* head;
    int count;

    void erase(Node* node);
};

extern "C" void __cdecl sub_80A058(void*);

void List::erase(Node* node) {
    Node* result;
    Node* n = node;
    if (n != this->head) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        if (n->vtable) {
            void (__stdcall *fn)(void*, int, void*);
            fn = *(void (__stdcall **)(void*, int, void*))n->vtable;
            if (fn) {
                fn(n + 1, 2, n + 1);
            }
            n->vtable = 0;
        }
        sub_80A058(n);
        this->count--;
    }
    result = this->head;
    *(Node**)&node = result;
}

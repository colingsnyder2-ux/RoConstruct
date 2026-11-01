// from server: 100% by colin
struct CXTPHookManagerHookAble {
    void Unlink(void* node);
    void Remove(void* node);
};

void CXTPHookManagerHookAble::Unlink(void* node) {
    struct Node {
        Node* next;
        Node* prev;
    };
    Node* n = (Node*)node;
    if (n == *(Node**)((char*)this + 4)) {
        *(Node**)((char*)this + 4) = n->next;
    } else {
        n->prev->next = n->next;
    }
    if (n == *(Node**)((char*)this + 8)) {
        *(Node**)((char*)this + 8) = n->prev;
        Remove(n);
    } else {
        n->next->prev = n->prev;
        Remove(n);
    }
}

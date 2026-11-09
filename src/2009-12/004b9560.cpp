// from server: 42% by atomic.potato
struct RbxManualResourceLoaderChain {
    void destroy();
};

void RbxManualResourceLoaderChain::destroy() {
    struct Node {
        Node* next;
        Node* prev;
        virtual void release(int) {}
    };

    Node* head = *reinterpret_cast<Node**>(reinterpret_cast<char*>(this) + 4);
    while (head != 0) {
        Node* cur = head;
        head = cur->next;
        cur->next = cur;
        cur->prev->release(1);
    }

    if (this != 0) {
        void (**vt)(void*) = *reinterpret_cast<void (***)(void*)>(this);
        vt[0](this);
    }
}

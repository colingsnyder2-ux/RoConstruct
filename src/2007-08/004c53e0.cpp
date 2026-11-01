// from server: 100% by colin
struct RakPeer {
    int state;
    void* head;
    void* tail;
    void clear();
};

extern "C" void __cdecl free(void*);

void RakPeer::clear() {
    if (state == 0) {
        return;
    }
    if (state == 1) {
        free(head);
        head = 0;
        state = 0;
        tail = 0;
        return;
    }
    void* node = tail;
    void* prev = *(void**)((char*)node + 4);
    void* next = *(void**)((char*)node + 8);
    *(void**)((char*)prev + 8) = next;
    node = tail;
    next = *(void**)((char*)node + 8);
    prev = *(void**)((char*)node + 4);
    *(void**)((char*)next + 4) = prev;
    node = tail;
    void* newTail = *(void**)((char*)node + 8);
    if (node == head) {
        head = newTail;
    }
    free(node);
    state--;
    tail = newTail;
}

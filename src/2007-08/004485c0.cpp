// from server: 100% by atomic.potato
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall RaiseException(unsigned long, unsigned long, unsigned long, const unsigned long*);
extern "C" void __cdecl sub_62FC62(void*);

struct Node {
    void (__stdcall *callback)(void*);
    void* arg;
    Node* next;
};

struct CIDEDocManager {
    void clear(Node* node);
};

void CIDEDocManager::clear(Node* node) {
    if (node == 0) {
        RaiseException(0xC0000005, 1, 0, 0);
    }
    Node* cur = node->next;
    while (cur != 0) {
        cur->callback(cur->arg);
        Node* next = cur->next;
        sub_62FC62(cur);
        cur = next;
    }
    node->next = 0;
}

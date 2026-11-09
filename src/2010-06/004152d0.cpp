// from server: 80% by atomic.potato
struct Node {
    Node* next;
    char pad[0x14];
    Node* prev;
};

struct List {
    Node* head;
    void remove_head();
};

extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);
extern void* __cdecl sub_401910();
extern void __cdecl sub_4150f0(void*);

void List::remove_head() {
    Node* p = head;
    if (p) {
        sub_4150f0(p);
        void* cs = sub_401910();
        EnterCriticalSection(cs);
        Node* q = *(Node**)((char*)cs + 0x18);
        p->next = q;
        *(Node**)((char*)cs + 0x18) = p;
        LeaveCriticalSection(cs);
    }
}

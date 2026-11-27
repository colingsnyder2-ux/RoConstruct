// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct CS { char d[0x18]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CS*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CS*);
struct Node { Node* next; };
struct Pool { CS cs; Node* freeList; };
Pool* getPool();
struct Sender {
    int pad;
    Node* node;
    void cleanup();
    void f();
};
void Sender::f() {
    cleanup();
    Node* n = node;
    Pool* p = getPool();
    EnterCriticalSection(&p->cs);
    n->next = p->freeList;
    p->freeList = n;
    LeaveCriticalSection(&p->cs);
    node = 0;
}

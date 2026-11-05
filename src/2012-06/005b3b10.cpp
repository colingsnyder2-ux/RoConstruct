// from server: 75% by atomic.potato
struct Node {
    Node* next;
    char pad[0x14];
};

struct Sender {
    char pad0[4];
    Node* field4;
    void f();
};

extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);
extern void* g_cs1;
extern void* g_cs2;

void sub_5b3750();
void* sub_5b2b20();

void Sender::f() {
    sub_5b3750();
    Node* b = field4;
    void* p = sub_5b2b20();
    EnterCriticalSection(&g_cs1);
    b->next = *(Node**)((char*)p + 0x18);
    *(void**)((char*)p + 0x18) = b;
    LeaveCriticalSection(&g_cs2);
    field4 = 0;
}

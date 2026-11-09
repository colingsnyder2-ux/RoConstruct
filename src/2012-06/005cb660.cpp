// from server: 54% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_00982114(void*);

struct Node {
    char pad0[4];
    Node* next;
    volatile long refcount;
    char pad2[4];
    virtual void destroy();
};

void __stdcall func_005cb660(Node* p)
{
    while (p) {
        Node* cur = p;
        Node* next = cur->next;
        Node* obj = (Node*)((char*)cur - 8);
        volatile long* rc = (volatile long*)((char*)cur + 4);
        if (*rc != 0) {
            if (_InterlockedExchangeAdd(rc, -1) == 1) {
                void** vt = *(void***)obj;
                void (*fn)(void*) = (void (*)(void*))vt[2];
                fn(obj);
            }
        }
        sub_00982114(obj);
        p = next;
    }
}

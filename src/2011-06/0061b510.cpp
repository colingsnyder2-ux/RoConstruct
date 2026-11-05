// from server: 44% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct LiveThreadRef {
    void addRef();
    void release();
    void* vtable;
};

struct Node {
    void release();
};

extern "C" void __cdecl free(void*);

struct WeakThreadRef {
    Node* node;
    LiveThreadRef* liveThreadRef;
    void release();
};

void WeakThreadRef::release()
{
    LiveThreadRef* lt = liveThreadRef;
    if (lt) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)lt + 4), -1) == 1) {
            lt->addRef();
            lt->release();
        }
    }
    Node* n = node;
    if (n) {
        if (_InterlockedExchangeAdd((volatile long*)n, -1) == 1) {
            if (n) {
                n->release();
                free(n);
            }
        }
    }
}

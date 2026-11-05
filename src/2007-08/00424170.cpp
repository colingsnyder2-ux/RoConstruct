// from server: 24% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct RefCounted {
    long refcount;
    long weakrefcount;
    virtual void destroy();
    virtual void weakdestroy();
};

struct Node {
    Node* next;
    Node* prev;
    void* data;
    RefCounted* obj;
};

struct List {
    Node* head;
    Node* tail;
};

struct Lock {
    void lock();
    void unlock();
};

struct CSelectionTreeCtrl {
    char pad[0xb0];
    Lock lock;
    char pad2[0xcc - 0xb0 - sizeof(Lock)];
    List list;

    void sub_424020(void*);
    void sub_421700(void*, void*, void*);
    void func();
};

void CSelectionTreeCtrl::func()
{
    int i;
    for (i = 0; i < 10; i++) {
        RefCounted* obj = 0;
        void* data = 0;
        Node* node;

        lock.lock();

        node = list.head->next;
        if (node != list.head) {
            data = node->data;
            obj = node->obj;
            if (obj) {
                _InterlockedExchangeAdd(&obj->refcount, 1);
            }
            sub_421700(this, &data, node);
        }

        lock.unlock();

        sub_424020(&data);

        if (obj) {
            if (_InterlockedExchangeAdd(&obj->refcount, -1) == 1) {
                obj->destroy();
                if (_InterlockedExchangeAdd(&obj->weakrefcount, -1) == 1) {
                    obj->weakdestroy();
                }
            }
        }
    }
}

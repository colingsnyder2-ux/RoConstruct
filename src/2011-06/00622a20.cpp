// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct LuaAllocator {
    void clearHeapMax();
    void Get(void*, void*, void*, void*);
};

struct RefCounted {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    volatile long refcount;
    volatile long refcount2;
};

struct Holder {
    RefCounted* ptr;
    RefCounted* ptr2;
};

struct LuaStatsItem {
    char pad[0x1f0];
    LuaAllocator* allocator;
    Holder* method(Holder* result, int a, int b);
};

Holder* LuaStatsItem::method(Holder* result, int a, int b) {
    void* v1;
    void* v2;
    void* v3;
    void* v4;
    allocator->Get(&v1, &v2, &v3, &v4);

    RefCounted* obj = (RefCounted*)operator new(0x10);
    if (obj) {
        obj->unknown0();
    } else {
        obj = 0;
    }

    Holder tmp;
    tmp.ptr = obj;
    tmp.ptr2 = 0;

    void* arr[4];
    arr[0] = v1;
    arr[1] = v2;
    arr[2] = v3;
    arr[3] = v4;

    void* p = (void*)&tmp;
    void* q = (void*)&arr;

    allocator->Get((char*)p + 0, q, 0, 0);
    allocator->Get((char*)p + 8, q, 0, 0);
    allocator->Get((char*)p + 0x10, q, 0, 0);
    allocator->Get((char*)p + 0x18, q, 0, 0);

    allocator->clearHeapMax();

    result->ptr = obj;
    result->ptr2 = tmp.ptr2;
    if (tmp.ptr2) {
        _InterlockedExchangeAdd(&tmp.ptr2->refcount, 1);
    }

    if (tmp.ptr2) {
        if (_InterlockedExchangeAdd(&tmp.ptr2->refcount, -1) == 1) {
            tmp.ptr2->unknown1();
            if (_InterlockedExchangeAdd(&tmp.ptr2->refcount2, -1) == 1) {
                tmp.ptr2->unknown2();
            }
        }
    }

    return result;
}

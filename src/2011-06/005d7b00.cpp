// from server: 58% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    volatile long refcount;
    volatile long weakrefcount;
};

struct Holder {
    RefCounted* ptr;
    RefCounted* ptr2;
};

extern "C" Holder* __cdecl sub_5D7A80(Holder* out);

struct VSelectionBox {
    Holder Create();
};

Holder VSelectionBox::Create() {
    Holder tmp;
    tmp.ptr = 0;
    tmp.ptr2 = 0;
    Holder* r = sub_5D7A80(&tmp);
    Holder result;
    RefCounted* p = r->ptr;
    if (p != 0) {
        result.ptr = (RefCounted*)((char*)p + 0x18);
    } else {
        result.ptr = 0;
    }
    result.ptr2 = r->ptr2;
    if (result.ptr2 != 0) {
        _InterlockedExchangeAdd(&result.ptr2->refcount, 1);
    }
    RefCounted* old = tmp.ptr;
    if (old != 0) {
        if (_InterlockedExchangeAdd(&old->refcount, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))old->vptr[1])(old);
            if (_InterlockedExchangeAdd(&old->weakrefcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))old->vptr[2])(old);
            }
        }
    }
    return result;
}

// from server: 30% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

extern "C" {
    void __stdcall StringCopyCtor(void* dst, const void* src);
    void __stdcall StringDtor(void* self);
}

struct VDataModel {
    void sub_86a370(const void* a, const void* b);
    void func(const void* a, const void* b, const void* c, const void* d, const void* e, const void* f, const void* g, const void* h, const void* i, const void* j, const void* k);
};

void VDataModel::func(const void* a, const void* b, const void* c, const void* d, const void* e, const void* f, const void* g, const void* h, const void* i, const void* j, const void* k) {
    char buf[0x1c];
    const void* local8;
    const void* localc;
    RefCounted* rc;
    char flag;

    StringCopyCtor(buf, a);
    local8 = b;
    localc = c;
    rc = (RefCounted*)d;
    if (rc) {
        _InterlockedExchangeAdd(&rc->refcount, 1);
    }
    sub_86a370(e, f);
    flag = 0;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            void** vt = *(void***)rc;
            void (*dtor)(void*) = (void (*)(void*))vt[2];
            dtor(rc);
        }
    }
    StringDtor(buf);
}

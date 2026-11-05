// from server: 34% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Inner {
    void* vptr;
    void* field4;
};

struct Obj78 {
    void* vptr;
    Inner* getInner();
};

struct Obj74 {
    char pad[0x120];
    void* vptr120;
};

struct CRobloxDoc {
    char pad0[0x74];
    Obj74* field74;
    Obj78* field78;
    void func();
};

extern "C" void* __stdcall sub_403800(void* out, void* arg);
extern "C" void __stdcall sub_40d550(void* p);
extern "C" void __stdcall sub_5595a0(void* p);

void CRobloxDoc::func()
{
    Inner* inner;
    void* tmp;
    RefCounted* rc;
    void* target;

    sub_403800(&inner, this->field78);
    tmp = inner->field4;
    if (tmp != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)tmp + 4), 1);
    }
    sub_40d550(&inner);

    rc = (RefCounted*)inner;
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            ((void (__stdcall*)(RefCounted*))rc->vptr)(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                ((void (__stdcall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
            }
        }
    }

    sub_403800(&inner, this->field78);
    target = inner->vptr;
    if (target != 0) {
        target = (char*)target + 0x160;
    } else {
        target = 0;
    }
    Obj74* o = this->field74;
    void* vt = *(void**)((char*)o + 0x120);
    ((void (__stdcall*)(void*, void*))((void**)vt)[4])((char*)o + 0x120, target);

    rc = (RefCounted*)inner;
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            ((void (__stdcall*)(RefCounted*))rc->vptr)(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                ((void (__stdcall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
            }
        }
    }

    sub_5595a0(&inner);
}

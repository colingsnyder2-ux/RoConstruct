// from server: 30% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
    long weakcount;
};

struct Main {
    char pad[0x78];
    void* field78;
    void method(int arg);
};

extern "C" void* __stdcall sub_403800(void* out, void* a);
extern "C" void* __stdcall sub_403830(void* out, void* a);
extern "C" void __stdcall sub_40d550(void* p);
extern "C" void* __stdcall sub_450ec0(void* p);
extern "C" void __stdcall sub_5595a0(void* p);

void Main::method(int arg)
{
    void* tmp18;
    void* tmp10;
    void* tmp20;
    void* tmp14;
    RefCounted* rc;
    long old;

    sub_403800(&tmp18, field78);

    tmp10 = *(void**)tmp18;
    tmp14 = *(void**)((char*)tmp18 + 4);
    *(void**)tmp10 = tmp14;
    if (tmp14 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)tmp14 + 4), 1);
    }

    sub_40d550(&tmp20);

    rc = (RefCounted*)tmp18;
    if (rc != 0) {
        old = _InterlockedExchangeAdd(&rc->refcount, -1);
        if (old == 1) {
            ((void (__thiscall*)(RefCounted*))rc->vptr)(rc);
            old = _InterlockedExchangeAdd(&rc->weakcount, -1);
            if (old == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
            }
        }
    }

    sub_403830(&tmp10, this);
    rc = (RefCounted*)tmp10;
    sub_450ec0(rc);
    if (rc != 0) {
        old = _InterlockedExchangeAdd(&rc->refcount, -1);
        if (old == 1) {
            ((void (__thiscall*)(RefCounted*))rc->vptr)(rc);
            old = _InterlockedExchangeAdd(&rc->weakcount, -1);
            if (old == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
            }
        }
    }

    sub_5595a0(&tmp20);
}

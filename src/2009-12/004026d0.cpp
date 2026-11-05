// from server: 44% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refcount;
    volatile long weakrefcount;
};

struct Holder {
    void* ptr;
    void* ctrl;
};

extern "C" void* __cdecl sub_402650(void** out);

struct VSelection {
    char pad[0x18];
    void* field18;
};

void __stdcall sub_4026d0(Holder* out, void* arg);

void __stdcall sub_4026d0(Holder* out, void* arg)
{
    void* tmp = 0;
    sub_402650(&tmp);
    void* p = *(void**)tmp;
    void* ctrl;
    if (p != 0)
        ctrl = (char*)p + 0x18;
    else
        ctrl = 0;
    out->ptr = ctrl;
    void* c2 = *(void**)((char*)tmp + 4);
    out->ctrl = c2;
    if (c2 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)c2 + 4), 1);
    }
    if (arg != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)arg + 4), -1) == 1) {
            void** vt = *(void***)arg;
            ((void (__stdcall*)(void*))vt[1])(arg);
            if (_InterlockedExchangeAdd((volatile long*)((char*)arg + 8), -1) == 1) {
                void** vt2 = *(void***)arg;
                ((void (__stdcall*)(void*))vt2[2])(arg);
            }
        }
    }
}

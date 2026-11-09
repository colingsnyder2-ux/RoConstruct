// from server: 50% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub {
    void** vptr;
    long ref1;
    long ref2;
};

struct S {
    char pad0[4];
    Sub* sub;
    char pad1[8];
    void* obj;
    char pad2[4];
    void* field18;
    void destroy();
};

void S::destroy()
{
    if (obj) {
        void** vt = *(void***)obj;
        void* p = field18;
        if (vt) {
            ((void (__stdcall*)(void*, void*, int))vt)(p, p, 2);
        }
        obj = 0;
    }
    Sub* s = sub;
    if (s) {
        if (_InterlockedExchangeAdd(&s->ref1, -1) == 1) {
            ((void (__stdcall*)(Sub*))s->vptr[1])(s);
            if (_InterlockedExchangeAdd(&s->ref2, -1) == 1) {
                ((void (__stdcall*)(Sub*))s->vptr[2])(s);
            }
        }
    }
}

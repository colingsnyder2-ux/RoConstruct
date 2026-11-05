// from server: 55% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall LeaveCriticalSection(void*);

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct MarshaledListener {
    void* vptr;
    char pad[0x14];
    void* field18;
    void method(int arg);
};

void helper1(void*);
void helper2(void*, void*);

void MarshaledListener::method(int arg)
{
    char local[0xc];
    void* p = (char*)field18 + 0x2c;
    *(void**)(local + 0) = p;
    *(char*)(local + 4) = 0;
    helper1(local);

    void* vtbl = *(void**)this;
    void* tmp = local + 0x18;
    void* dst = local + 0x0;
    helper2(dst, tmp);

    void* argp = *(void**)(local + 0x14);
    void* fn = *(void**)((char*)vtbl + 0xc);
    typedef void (__thiscall *Fn)(void*, void*);
    ((Fn)fn)(this, argp);

    if (*(char*)(local + 4) != 0) {
        LeaveCriticalSection(*(void**)(local + 0));
    }

    RefCounted* rc = *(RefCounted**)(local + 0x14);
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void* vt = rc->vptr;
            void* fn2 = *(void**)((char*)vt + 4);
            typedef void (__thiscall *Fn2)(void*);
            ((Fn2)fn2)(rc);
            if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                void* vt2 = rc->vptr;
                void* fn3 = *(void**)((char*)vt2 + 8);
                typedef void (__thiscall *Fn3)(void*);
                ((Fn3)fn3)(rc);
            }
        }
    }
}

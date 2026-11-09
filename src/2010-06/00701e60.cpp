// from server: 17% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_00700B00();

struct RefCounted
{
    void* vptr;
    volatile long refcount;
};

struct EventDesc
{
    void* vptr;
    char pad[4];
    void* field8;
    void __cdecl f(void* a, void* b, void* c, void* d);
};

void __cdecl EventDesc::f(void* a, void* b, void* c, void* d)
{
    void* local[4];
    local[0] = a;
    local[1] = b;
    local[2] = c;
    local[3] = d;

    void* saved = 0;
    if (d)
    {
        _InterlockedExchangeAdd((volatile long*)((char*)d + 4), 1);
    }

    sub_00700B00();
    unsigned char al = 0;
    void* result = al ? (void*)0x00BE0C5C : (void*)0;
    *(void**)this = result;

    if (saved)
    {
        RefCounted* r = (RefCounted*)saved;
        if (_InterlockedExchangeAdd(&r->refcount, -1) == 1)
        {
            void (*fn)(void*) = *(void (**)(void*))((char*)*(void**)r + 4);
            fn(r);
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1)
            {
                void (*fn2)(void*) = *(void (**)(void*))((char*)*(void**)r + 8);
                fn2(r);
            }
        }
    }
}

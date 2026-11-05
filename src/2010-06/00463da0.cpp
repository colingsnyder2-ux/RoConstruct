// from server: 33% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted
{
    void* vptr;
    long refcount;
};

struct Outer
{
    char pad0[0x378];
    char list[8];
    char pad1[0x39c - 0x380];
    char flag;
    char pad2[0x3b4 - 0x39d];
    RefCounted* a;
    RefCounted* b;
    void func_00463da0();
};

extern "C" void __cdecl func_0041ae20();
extern "C" void* __cdecl func_007a79a0(unsigned long);
extern "C" void* __cdecl func_007a7c82(unsigned long);
extern "C" void* __cdecl func_009ea380();
extern "C" void* __cdecl func_009ea310(void*, int, unsigned long);

extern "C" int __cdecl func_00462b10(void* self, void* arg);
extern "C" void __cdecl func_004636b0(void* self, void* arg);
extern "C" void __cdecl func_00463ba0(void* self);
extern "C" int __cdecl func_007e1780(void* self);
extern "C" void* __cdecl func_007e0cb0(void* self, int idx);
extern "C" void __cdecl func_007e1060(void* self, int idx);

extern void* g_00c2558c;
extern int g_00c25598;

void Outer::func_00463da0()
{
    void* edi;
    void* ebp;
    void* local1c;
    void* local20;
    int local30;
    void* local14;
    char local24;

    flag = 0;

    edi = ((void* (__cdecl*)(void*))((*(void***)this)[0x194 / 4]))(this);
    ebp = *(void**)((char*)edi + 0xe8);

    local1c = 0;
    local20 = 0;
    local30 = 0;

    while (func_00462b10(list, &local1c))
    {
        if (local24)
        {
            if (g_00c25598)
            {
                func_009ea380();
                if (g_00c25598)
                {
                    func_0041ae20();
                    local14 = func_009ea310(g_00c2558c, 0, 0xa0);
                }
                else
                {
                    local14 = func_007a7c82(0xa0);
                }
            }
            else
            {
                func_009ea380();
                local14 = func_007a79a0(0xa0);
            }

            if (local14)
            {
                RefCounted* ra = a;
                RefCounted* rb = b;
                if (rb)
                    _InterlockedExchangeAdd(&rb->refcount, 1);
                if (ra)
                    _InterlockedExchangeAdd(&ra->refcount, 1);
                func_004636b0(local14, 0);
            }
            else
            {
                local14 = 0;
            }

            ((void (__cdecl*)(void*, void*))((*(void***)edi)[0x14c / 4]))(edi, local14);
        }
        else
        {
            int n = func_007e1780(ebp) - 1;
            while (n >= 0)
            {
                void* p = func_007e0cb0(ebp, n);
                if (*(void**)((char*)p + 0x98) == local1c)
                {
                    func_007e1060(ebp, n);
                    break;
                }
                n--;
            }
        }
    }

    int n = func_007e1780(ebp) - 1;
    while (n >= 0)
    {
        func_00463ba0(func_007e0cb0(ebp, n));
        n--;
    }

    if (local20)
    {
        RefCounted* r = (RefCounted*)local20;
        if (_InterlockedExchangeAdd(&r->refcount, -1) == 1)
        {
            ((void (__cdecl*)(void*))((*(void***)r)[1]))(r);
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1)
            {
                ((void (__cdecl*)(void*))((*(void***)r)[2]))(r);
            }
        }
    }
}

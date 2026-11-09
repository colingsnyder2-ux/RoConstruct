// from server: 30% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted
{
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Inner
{
    void* vptr;
};

struct S
{
    void f(void* a, void* b, void* c, void* d);
};

extern "C" void __cdecl sub_66faf0(void*, void*, void*);
extern "C" void __cdecl sub_4b9dd0(void*);
extern "C" void __cdecl sub_5fcdc0(void*, void*, void*, void*, int);

extern unsigned char byte_C189D5;
extern void* ptr_4B2EB0;

void S::f(void* a, void* b, void* c, void* d)
{
    void* local0 = 0;
    void* local1 = 0;
    void* local2 = 0;
    void* local3 = 0;
    void* local4 = 0;
    void* local5 = 0;
    void* local6 = 0;
    void* local7 = 0;
    void* local8 = 0;
    void* local9 = 0;
    void* local10 = 0;
    void* local11 = 0;
    void* local12 = 0;
    void* local13 = 0;
    void* local14 = 0;
    void* local15 = 0;

    unsigned char flag = byte_C189D5;

    void* args[2];
    args[0] = c;
    args[1] = d;

    void* obj = a;
    if (obj != 0)
    {
        _InterlockedExchangeAdd((volatile long*)((char*)obj + 4), 1);
    }

    sub_66faf0(&local0, ptr_4B2EB0, args);
    sub_4b9dd0(&local0);

    sub_5fcdc0(this, b, &local0, (void*)0xa, 0);

    void* p = local1;
    if (p != 0)
    {
        void* fn = *(void**)p;
        if (fn != 0)
        {
            ((void(__cdecl*)(void*, void*, int))fn)(&local1, &local1, 2);
        }
        local1 = 0;
    }

    RefCounted* rc = (RefCounted*)local2;
    if (rc != 0)
    {
        if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1)
        {
            ((void(__cdecl*)(void*))rc->vptr)(rc);
            if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1)
            {
                ((void(__cdecl*)(void*))rc->vptr)(rc);
            }
        }
    }
}

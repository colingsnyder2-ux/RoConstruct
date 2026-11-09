// from server: 30% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void *__cdecl sub_7f3860(int);
extern "C" void __cdecl sub_508210(void *, void *, void *);
extern "C" void __cdecl sub_50ec70(void *);
extern "C" void __cdecl sub_76ccc0(void *, void *, void *, int, int);

struct RefCounted
{
    void *vptr;
    long refcount;
};

struct VPlayer
{
    void func(void *, void *, void *, int, int);
};

void VPlayer::func(void *a, void *b, void *c, int d, int e)
{
    void *p = sub_7f3860(4);
    if (p != 0)
        *(void **)p = 0;
    else
        p = 0;

    void *local[6];
    local[0] = p;
    local[3] = 0;
    local[4] = 0;
    local[5] = 0;

    void *args[2];
    args[0] = a;
    args[1] = b;

    if (c != 0)
        _InterlockedExchangeAdd((volatile long *)((char *)c + 4), 1);

    sub_508210(local[0], (void *)0x505d40, 0);

    sub_50ec70((char *)local + 0x10);

    sub_76ccc0(this, local[4], local[5], 0xa, (int)local);

    if (local[0] != 0)
    {
        void *vt = *(void **)local[0];
        if (vt != 0)
        {
            void (*fn)(void *, void *, int) = *(void (**)(void *, void *, int))vt;
            fn((char *)local + 0x10, (char *)local + 0x10, 2);
        }
        local[0] = 0;
    }

    if (c != 0)
    {
        if (_InterlockedExchangeAdd((volatile long *)((char *)c + 4), -1) == 1)
        {
            void *vt = *(void **)c;
            void (*fn)(void *) = *(void (**)(void *))((char *)vt + 4);
            fn(c);
            if (_InterlockedExchangeAdd((volatile long *)((char *)c + 8), -1) == 1)
            {
                void *vt2 = *(void **)c;
                void (*fn2)(void *) = *(void (**)(void *))((char *)vt2 + 8);
                fn2(c);
            }
        }
    }
}

// from server: 20% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted
{
    long refs;
    void (__thiscall *fn4)(RefCounted*);
    void (__thiscall *fn8)(RefCounted*);
};

struct S
{
    int field0;
    void construct(int, int, int, int, int, int, int, int);
};

extern "C" void __stdcall helper(S*, int, int, int, int, int, int, int, int);

void S::construct(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    int local[6];
    RefCounted* rc;

    this->field0 = 0;
    local[0] = a1;
    local[1] = a2;
    local[2] = a3;
    local[3] = a4;
    local[4] = a5;
    rc = (RefCounted*)a6;
    if (rc)
        _InterlockedExchangeAdd(&rc->refs, 1);
    local[5] = a7;
    helper(this, local[0], local[1], local[2], local[3], local[4], (int)rc, local[5], a8);
    if (rc)
    {
        if (_InterlockedExchangeAdd(&rc->refs, -1) == 1)
        {
            rc->fn4(rc);
            if (_InterlockedExchangeAdd(&rc->refs, -1) == 1)
                rc->fn8(rc);
        }
    }
}

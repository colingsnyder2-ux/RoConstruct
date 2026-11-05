// from server: 96% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct SphereBuilder
{
    void* construct(int a, int b, int* c);
};

void* SphereBuilder::construct(int a, int b, int* c)
{
    char* p = (char*)operator new(0x14);
    if (p)
    {
        *(int*)p = a;
    }
    int* q = (int*)(p + 4);
    if (q)
    {
        *q = b;
    }
    int* r = (int*)(p + 8);
    if (r)
    {
        r[0] = c[0];
        r[1] = c[1];
        r[2] = c[2];
        if (r[2])
        {
            _InterlockedExchangeAdd((volatile long*)(r[2] + 8), 1);
        }
    }
    return p;
}

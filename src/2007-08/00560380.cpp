// from server: 50% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct FilteredSelection
{
    void __cdecl for_each_helper(int a, int b, int c, int d, int e, int f);
};

void FilteredSelection::for_each_helper(int a, int b, int c, int d, int e, int f)
{
    int* begin = (int*)a;
    int* end = (int*)b;
    while (begin != end)
    {
        int v0 = begin[0];
        int v1 = begin[1];
        int local[2];
        local[0] = v0;
        local[1] = v1;
        if (v1 != 0)
        {
            _InterlockedExchangeAdd((volatile long*)(v1 + 4), 1);
        }
        ((void (__stdcall*)(int, int, int*, int, int))f)(c, d, local, e, 0);
        begin += 2;
    }
    int* out = (int*)e;
    out[0] = c;
    out[1] = d;
    out[2] = a;
    out[3] = b;
}

// from server: 62% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_0060d940 {
    void* vptr;
    char pad_4[176];
    long f_b4;
    volatile long* f_b8;
    void get(long* out);
};

void S_0060d940::get(long* out)
{
    out[0] = f_b4;
    volatile long* p = f_b8;
    out[1] = (long)p;
    if (p)
        _InterlockedExchangeAdd(p + 1, 1);
}

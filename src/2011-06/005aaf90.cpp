// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct T4_005aaf90 {
    int m_0;
    int m_4;
};

extern "C" void f_005a7e40(void*);
extern "C" char f_005a9440(int);

int f_005aaf90(T4_005aaf90* self, int a, int b, int c, int d, int e, int f)
{
    int result;
    int local[6];
    local[0] = a;
    local[1] = b;
    local[2] = c;
    if (c)
        _InterlockedExchangeAdd((volatile long*)(c + 8), 1);
    local[3] = d;
    local[4] = e;
    local[5] = f;
    if (f)
        _InterlockedExchangeAdd((volatile long*)(f + 4), 1);
    result = f_005a9440(0xc3a9fc);
    result = -(int)(unsigned char)result;
    result = result & 0xc3a9fc;
    self->m_0 = result;
    f_005a7e40(&local[0]);
    return result;
}

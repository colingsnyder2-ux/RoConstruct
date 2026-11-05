// from server: 16% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl func_5f6700();
extern "C" void* __cdecl func_5f6df0();
extern "C" void* __cdecl func_5f6e80();
extern "C" void* __cdecl func_430a10(void*, void*);

struct S_func_00784490 {
    char pad0[0x20];
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    char m_38[8];
    void f(int, int, int, int);
};

void S_func_00784490::f(int a1, int a2, int a3, int a4)
{
    if (a1 == 0) {
        float v[4];
        v[0] = *(float*)0x9aea18;
        v[1] = v[0];
        v[2] = v[0];
        v[3] = *(float*)0x9af2dc;
        void* p = func_5f6700();
        int tmp[2];
        tmp[0] = m_28;
        tmp[1] = m_2c;
        if (tmp[1] != 0) {
            _InterlockedExchangeAdd((volatile long*)(tmp[1] + 4), 1);
        }
        func_430a10(v, p);
        return;
    }
    if (a1 == 0) {
        void* p1 = func_5f6700();
        void* p2 = func_5f6700();
        int tmp[2];
        tmp[0] = m_20;
        tmp[1] = m_24;
        if (tmp[1] != 0) {
            _InterlockedExchangeAdd((volatile long*)(tmp[1] + 4), 1);
        }
        func_430a10(tmp, p2);
        return;
    }
    if (a1 == 1 || a1 == 3) {
        float* e = (float*)func_5f6e80();
        float v[4];
        v[0] = e[0];
        v[1] = e[1];
        v[2] = e[2];
        v[3] = *(float*)0x9aea18;
        void* p = func_5f6700();
        int tmp[2];
        tmp[0] = m_30;
        tmp[1] = m_34;
        if (tmp[1] != 0) {
            _InterlockedExchangeAdd((volatile long*)(tmp[1] + 4), 1);
        }
        func_430a10(v, p);
        return;
    }
    float* e = (float*)func_5f6df0();
    float v[4];
    v[0] = e[0];
    v[1] = e[1];
    v[2] = e[2];
    v[3] = *(float*)0x9aea18;
    void* p = func_5f6700();
    func_430a10(v, p);
}

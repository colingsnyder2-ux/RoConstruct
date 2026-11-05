// from server: 27% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct T4_0069e880 {
    int m_ref;
    char m_pad[4];
    int m_ref2;
};

extern "C" void __cdecl sub_00801040();

void f_0069e880(T4_0069e880* self, int a, int b, int c, int d)
{
    int old;
    void (__stdcall *fn)(void*);

    _InterlockedExchangeAdd((volatile long*)((char*)self + 8), 1);

    sub_00801040();

    self->m_ref = 0;

    if (d != 0) {
        old = _InterlockedExchangeAdd((volatile long*)((char*)d + 4), -1);
        if (old == 1) {
            fn = *(void (__stdcall **)(void*))d;
            fn((void*)d);
            old = _InterlockedExchangeAdd((volatile long*)((char*)d + 8), -1);
            if (old == 1) {
                fn = *(void (__stdcall **)(void*))d;
                fn((void*)d);
            }
        }
    }
}

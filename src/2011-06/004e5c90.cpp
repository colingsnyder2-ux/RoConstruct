// from server: 38% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_func_004e5c90 {
    void* m_p0;
    void* m_p4;
    void* f(void* a, void* b);
};

void __stdcall sub_004e5b00(void*, void*);

void* S_func_004e5c90::f(void* a, void* b)
{
    m_p0 = a;
    sub_004e5b00(&m_p4, b);
    if (a != 0) {
        char* edi = (char*)a + 0x2c;
        if (edi != 0) {
            *(void**)edi = a;
            void* esi = m_p4;
            if (esi != *(void**)(edi + 4)) {
                if (esi != 0) {
                    _InterlockedExchangeAdd((volatile long*)((char*)esi + 8), 1);
                }
                void* ecx = *(void**)(edi + 4);
                if (ecx != 0) {
                    if (_InterlockedExchangeAdd((volatile long*)((char*)ecx + 8), -1) == 1) {
                        void** vt = *(void***)ecx;
                        void (*fn)(void*) = (void (*)(void*))vt[2];
                        fn(ecx);
                    }
                }
                *(void**)(edi + 4) = esi;
            }
        }
    }
    return this;
}

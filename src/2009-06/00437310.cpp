// from server: 38% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S {
    void* field0;
    void* field4;
    char pad8[0x1c];
    void* field24;
    void* field28;
    S* init(void* a, void* b);
};

void __stdcall sub_437280(void* a, void* b);

S* S::init(void* a, void* b) {
    field0 = a;
    sub_437280(&field4, b);
    if (a != 0) {
        void** edi = (void**)((char*)a + 0x24);
        if (edi != 0) {
            *edi = a;
            void* esi = field4;
            if (esi != edi[1]) {
                if (esi != 0) {
                    _InterlockedExchangeAdd((volatile long*)((char*)esi + 8), 1);
                }
                void* ecx = edi[1];
                if (ecx != 0) {
                    if (_InterlockedExchangeAdd((volatile long*)((char*)ecx + 8), -1) == 1) {
                        void** vt = *(void***)ecx;
                        void (*fn)(void*) = (void (*)(void*))vt[2];
                        fn(ecx);
                    }
                }
                edi[1] = esi;
            }
        }
    }
    return this;
}

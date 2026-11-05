// from server: 24% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl func_4015a0();
extern "C" void __cdecl func_424d70();
extern "C" void __cdecl func_439330();
extern "C" void __cdecl func_4d30a0();
extern "C" void __cdecl func_59a790();
extern "C" void __cdecl func_8c4680();
extern "C" void* __cdecl func_98211a();
extern "C" void __cdecl func_9831f5();
extern "C" void __cdecl func_4ce470();
extern "C" void __cdecl func_4026a0();

struct S {
    void f();
};

void S::f()
{
    char* p1 = (char*)0xe1c368;
    char* p2 = (char*)0xe1c39c;
    char* p3 = (char*)0xe1c3bc;
    char* p4 = (char*)0xe1c3a4;
    char* p5 = (char*)0xe1c36c;
    char* p6 = (char*)0xe1c364;
    char* p7 = (char*)0xe1c398;
    char* p8 = (char*)0xe1c3a0;

    func_4015a0();
    if ((*(unsigned char*)p5 & 1) == 0) {
        *(unsigned int*)p5 |= 1;
        *p1 = 0;
    }
    func_424d70();
    func_4015a0();
    if ((*(unsigned char*)p4 & 1) == 0) {
        *(unsigned int*)p4 |= 1;
        *(unsigned int*)p2 = 0;
        *(unsigned int*)p8 = 0;
        func_9831f5();
    }
    func_439330();
    if (*(unsigned int*)p7 == 0) {
        *(unsigned int*)p6 += 1;
        void* mem = func_98211a();
        if (mem != 0) {
            *(unsigned int*)mem = 0;
            *(unsigned int*)((char*)mem + 4) = 0xffffffff;
            *(unsigned int*)((char*)mem + 8) = 0;
            *(unsigned int*)((char*)mem + 0xc) = 0;
            *(unsigned int*)((char*)mem + 0x10) = 0;
            *(unsigned int*)((char*)mem + 0x14) = 0;
            *(unsigned int*)((char*)mem + 0x18) = 0;
            *(unsigned int*)((char*)mem + 0x1c) = 0;
        }
        func_4d30a0();
        func_59a790();
        func_4026a0();
        void* obj = (void*)0;
        if (obj != 0) {
            long old = _InterlockedExchangeAdd((volatile long*)((char*)obj + 4), -1);
            if (old == 1) {
                (*(void(**)(void*))obj)(obj);
                long old2 = _InterlockedExchangeAdd((volatile long*)((char*)obj + 8), -1);
                if (old2 == 1) {
                    (*(void(**)(void*))(*(void**)obj))(obj);
                }
            }
        }
        func_4ce470();
        func_8c4680();
    }
    *p1 = *(char*)p1;
}

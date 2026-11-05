// from server: 46% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall G1_func_00432530();
extern "C" void __stdcall G1_func_0062fc62();
extern "C" void __stdcall G1_func_0054a270();
extern "C" void __stdcall G1_func_0055bac0();
extern "C" void __stdcall G1_func_00564aa0();
extern "C" void __stdcall G1_func_0077e6ac();

struct S {
    void func_0055ca50();
};

void S::func_0055ca50()
{
    char* base = (char*)this;
    *(int*)(base + 0x00) = 0x7a8db4;
    *(int*)(base + 0x04) = 0x7a8da8;
    *(int*)(base + 0x10) = 0x7a8da0;
    *(int*)(base + 0x14) = 0x7a8d90;
    *(int*)(base + 0x2c) = 0x7a8d80;
    *(int*)(base + 0x44) = 0x7a8d70;
    *(int*)(base + 0x5c) = 0x7a8d60;
    *(int*)(base + 0x74) = 0x7a8d50;
    *(int*)(base + 0x8c) = 0x7a8d40;
    *(int*)(base + 0xe8) = 0x7a8d30;
    *(int*)(base + 0x100) = 0x7a8d20;
    *(int*)(base + 0x118) = 0x7a8d10;
    *(int*)(base + 0x14c) = 0x7a8d08;
    *(int*)(base + 0x160) = 0x7a8cf8;
    *(int*)(base + 0x178) = 0x7a8cf0;
    *(int*)(base + 0x17c) = 0x7a8ce4;

    int* p190 = *(int**)(base + 0x190);
    if (p190 != 0) {
        G1_func_00432530();
    }

    G1_func_0062fc62();

    int* p1dc = *(int**)(base + 0x1dc);
    if (p1dc != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p1dc + 4), -1) == 1) {
            (*(void(**)(void*))(*(int*)p1dc + 4))(p1dc);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p1dc + 8), -1) == 1) {
                (*(void(**)(void*))(*(int*)p1dc + 8))(p1dc);
            }
        }
    }

    G1_func_0077e6ac();

    int* p1ac = *(int**)(base + 0x1ac);
    if (p1ac != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p1ac + 4), -1) == 1) {
            (*(void(**)(void*))(*(int*)p1ac + 4))(p1ac);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p1ac + 8), -1) == 1) {
                (*(void(**)(void*))(*(int*)p1ac + 8))(p1ac);
            }
        }
    }

    int* p1a4 = *(int**)(base + 0x1a4);
    if (p1a4 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p1a4 + 4), -1) == 1) {
            (*(void(**)(void*))(*(int*)p1a4 + 4))(p1a4);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p1a4 + 8), -1) == 1) {
                (*(void(**)(void*))(*(int*)p1a4 + 8))(p1a4);
            }
        }
    }

    int* p19c = *(int**)(base + 0x19c);
    if (p19c != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p19c + 4), -1) == 1) {
            (*(void(**)(void*))(*(int*)p19c + 4))(p19c);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p19c + 8), -1) == 1) {
                (*(void(**)(void*))(*(int*)p19c + 8))(p19c);
            }
        }
    }

    int* p194 = *(int**)(base + 0x194);
    if (p194 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p194 + 4), -1) == 1) {
            (*(void(**)(void*))(*(int*)p194 + 4))(p194);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p194 + 8), -1) == 1) {
                (*(void(**)(void*))(*(int*)p194 + 8))(p194);
            }
        }
    }

    int* p18c = *(int**)(base + 0x18c);
    if (p18c != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p18c + 4), -1) == 1) {
            (*(void(**)(void*))(*(int*)p18c + 4))(p18c);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p18c + 8), -1) == 1) {
                (*(void(**)(void*))(*(int*)p18c + 8))(p18c);
            }
        }
    }

    int* p184 = *(int**)(base + 0x184);
    if (p184 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p184 + 4), -1) == 1) {
            (*(void(**)(void*))(*(int*)p184 + 4))(p184);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p184 + 8), -1) == 1) {
                (*(void(**)(void*))(*(int*)p184 + 8))(p184);
            }
        }
    }

    *(int*)(base + 0x17c) = 0x795b54;
    G1_func_0055bac0();
    G1_func_00564aa0();
    G1_func_0054a270();
}

// from server: 41% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct S {
    char pad[0x78];
    void* field78;
    void method(int);
};

extern "C" void* __cdecl func_00403800(void*);
extern "C" void* __cdecl func_00403830(void*);
extern "C" void __cdecl func_0040d550(void*);
extern "C" void* __cdecl func_0042e410(void*);
extern "C" void __cdecl func_005595a0(void*);

void S::method(int arg)
{
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
    void* p6;
    void* p7;
    void* p8;
    void* p9;
    void* p10;

    p1 = func_00403800(field78);
    p2 = *(void**)p1;
    p3 = *(void**)((char*)p1 + 4);
    if (p3 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p3 + 4), 1);
    }
    func_0040d550(&p4);
    if (p5 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p5 + 4), -1) == 1) {
            (*(void(__thiscall**)(void*))p5)(p5);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p5 + 8), -1) == 1) {
                (*(void(__thiscall**)(void*))((*(void***)p5)[2]))(p5);
            }
        }
    }
    p6 = func_00403830(&p7);
    p8 = *(void**)p6;
    if (p8 != 0) {
        p9 = func_0042e410(p8);
    } else {
        p9 = 0;
    }
    if (p10 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p10 + 4), -1) == 1) {
            (*(void(__thiscall**)(void*))p10)(p10);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p10 + 8), -1) == 1) {
                (*(void(__thiscall**)(void*))((*(void***)p10)[2]))(p10);
            }
        }
    }
    int flag = 0;
    if (p9 != 0) {
        if (*(int*)((char*)p9 + 0xf0) != 0) {
            flag = 1;
        }
    }
    (*(void(__thiscall**)(void*, int))p1)(p1, flag);
    func_005595a0(&p2);
}

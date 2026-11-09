// from server: 48% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long ref1;
    long ref2;
};

struct String {
    char _buf[28];
};

struct Exception {
    char _buf[4];
};

struct VFunctionalTest {
    char _pad[4];
    void runTest(int a1, int a2);
};

extern "C" void __stdcall func_008810c0(int*, String*);
extern "C" int __cdecl func_007eb2c0(int);
extern "C" int __cdecl func_0040c0a0(Exception*, const char*);
extern "C" int __cdecl func_00983144(int, Exception*);
extern "C" int __cdecl func_006b03c0(int, int);

void VFunctionalTest::runTest(int a1, int a2) {
    int v4 = 0;
    String str;
    func_008810c0(&v4, &str);

    char state = 1;
    if (v4) {
        int sp = func_007eb2c0((int)this);
        if (!sp) {
            Exception ex;
            func_0040c0a0(&ex, "Unable to start test script");
            state = 2;
            int v5 = func_00983144(0xcd806c, &ex);
            int v6 = func_006b03c0(v4, v5);
        } else {
            int v6 = func_006b03c0(v4, sp);
        }
    }

    RefCounted* obj1 = (RefCounted*)a2;
    if (obj1) {
        state = 0;
        if (_InterlockedExchangeAdd(&obj1->ref1, -1) == 1) {
            void (__thiscall *dtor)(RefCounted*) = (void (__thiscall*)(RefCounted*))obj1->vptr;
            dtor(obj1);
            if (_InterlockedExchangeAdd(&obj1->ref2, -1) == 1) {
                void (__thiscall *deleter)(RefCounted*) = (void (__thiscall*)(RefCounted*))((char*)obj1->vptr + 8);
                deleter(obj1);
            }
        }
    }

    RefCounted* obj2 = (RefCounted*)a1;
    if (obj2) {
        if (_InterlockedExchangeAdd(&obj2->ref1, -1) == 1) {
            void (__thiscall *dtor)(RefCounted*) = (void (__thiscall*)(RefCounted*))obj2->vptr;
            dtor(obj2);
            if (_InterlockedExchangeAdd(&obj2->ref2, -1) == 1) {
                void (__thiscall *deleter)(RefCounted*) = (void (__thiscall*)(RefCounted*))((char*)obj2->vptr + 8);
                deleter(obj2);
            }
        }
    }
}

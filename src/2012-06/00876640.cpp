// from server: 52% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    int vptr;
    long ref1;
    long ref2;
    virtual void Release1() = 0;
    virtual void Release2() = 0;
};

struct Unknown {
    int vptr;
    char pad[0x248];
    char flag;
};

extern "C" void __stdcall func_00439330(int*);

struct NotificationBox {
    void Method(int a1, RefCounted* a2);
};

void NotificationBox::Method(int a1, RefCounted* a2) {
    int v;
    func_00439330(&v);
    if (v) {
        *reinterpret_cast<char*>(v + 0x24C) = 1;
    }
    if (a2) {
        if (_InterlockedExchangeAdd(&a2->ref1, -1) == 1) {
            a2->Release1();
        }
        if (_InterlockedExchangeAdd(&a2->ref2, -1) == 1) {
            a2->Release2();
        }
    }
    if (a1) {
        RefCounted* obj = reinterpret_cast<RefCounted*>(a1);
        if (_InterlockedExchangeAdd(&obj->ref2, -1) == 1) {
            obj->Release2();
        }
    }
}

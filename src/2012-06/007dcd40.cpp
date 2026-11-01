// from server: 30% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    int vptr;
    long ref1;
    long ref2;
    virtual void Release1() = 0;
    virtual void Release2() = 0;
};

void __cdecl func_788080(void* p);
void __cdecl func_788100(void* p);
void __cdecl func_788180(void* p);
void __cdecl func_788200(void* p);
void __cdecl func_788280(void* p);
void __cdecl func_788300(void* p);
void __cdecl func_788380(void* p);
void __cdecl func_788400(void* p);
void __cdecl func_788480(void* p);
void __cdecl func_788500(void* p);
void __cdecl func_53e3a0(void* p);
void __cdecl func_53e420(void* p);

void __cdecl sub_7DCD40(RefCounted* esi) {
    void* guard1;
    func_788080(&guard1);
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            esi->Release1();
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1)
                esi->Release2();
        }
    }
    func_788100(&guard1);

    void* guard2;
    func_788180(&guard2);
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            esi->Release1();
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1)
                esi->Release2();
        }
    }
    func_788200(&guard2);

    void* guard3;
    func_788280(&guard3);
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            esi->Release1();
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1)
                esi->Release2();
        }
    }
    func_788300(&guard3);

    void* guard4;
    func_788380(&guard4);
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            esi->Release1();
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1)
                esi->Release2();
        }
    }
    func_788400(&guard4);

    void* guard5;
    func_788480(&guard5);
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            esi->Release1();
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1)
                esi->Release2();
        }
    }
    func_788500(&guard5);

    void* guard6;
    func_53e3a0(&guard6);
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            esi->Release1();
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1)
                esi->Release2();
        }
    }
    func_53e420(&guard6);

    void* guard7;
    func_788280(&guard7);
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            esi->Release1();
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1)
                esi->Release2();
        }
    }
    func_788280(&guard7);
}

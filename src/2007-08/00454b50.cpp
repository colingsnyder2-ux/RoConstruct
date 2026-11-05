// from server: 36% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct Sub54 {
    void* vptr;
};

struct Sub70 {
    void* vptr;
};

struct Sub8C {
    void* vptr;
};

struct Target {
    void* vptr;
    char pad[0x50];
    Sub54 sub54;
    char pad2[0x18];
    Sub70 sub70;
    char pad3[0x18];
    Sub8C sub8c;
    char pad4[0x8];
    void* field98;
    RefCounted* field9c;

    Target(void* a, RefCounted* b);
};

extern "C" void __cdecl func_661d90();
extern "C" void __cdecl func_661e20(void*);
extern "C" void* __cdecl func_654d90(unsigned int);
extern "C" void __cdecl func_40d550(void*);
extern "C" void __cdecl func_5595a0(void*);
extern "C" void __cdecl func_4536a0(void*);
extern "C" void __cdecl func_453fe0(void*);
extern "C" void __cdecl func_454050(void*);
extern "C" void __cdecl func_453a30(void*, void*, void*);
extern "C" void __cdecl func_453bb0(void*, void*, void*);
extern "C" void __cdecl func_423240(void*, void*);

Target::Target(void* a, RefCounted* b)
{
    func_661d90();

    void* arg1 = a;
    RefCounted* arg2 = b;

    if (arg2) {
        _InterlockedExchangeAdd(&arg2->refCount, 1);
    }

    func_4536a0(&this->sub8c);

    func_453fe0(&this->sub54);

    func_454050(&this->sub70);

    this->vptr = (void*)0x7923ec;
    this->sub54.vptr = (void*)0x792454;
    this->sub70.vptr = (void*)0x7923d8;
    this->field98 = arg1;
    this->field9c = arg2;

    if (arg2) {
        _InterlockedExchangeAdd(&arg2->refCount, 1);
    }

    void* p1 = func_654d90(0x88);
    if (p1) {
        if (arg2) {
            _InterlockedExchangeAdd(&arg2->refCount, 1);
        }
        func_453a30(p1, arg1, arg2);
    } else {
        p1 = 0;
    }
    func_661e20(p1);

    void* p2 = func_654d90(0x88);
    if (p2) {
        if (arg2) {
            _InterlockedExchangeAdd(&arg2->refCount, 1);
        }
        func_453bb0(p2, arg1, arg2);
    } else {
        p2 = 0;
    }
    func_661e20(p2);

    if (arg2) {
        _InterlockedExchangeAdd(&arg2->refCount, 1);
    }

    func_40d550(&this->sub8c);

    void* local = this->field98;
    if (local) {
        func_423240((char*)local + 0x14, &this->sub54);
        func_423240((char*)local + 0x2c, &this->sub70);
    }

    func_5595a0(&this->sub8c);

    if (this->field9c) {
        RefCounted* rc = this->field9c;
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void** vt = (void**)rc->vptr;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(rc);
            if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                void** vt2 = (void**)rc->vptr;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(rc);
            }
        }
    }

    if (arg2) {
        if (_InterlockedExchangeAdd(&arg2->refCount, -1) == 1) {
            void** vt = (void**)arg2->vptr;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(arg2);
            if (_InterlockedExchangeAdd(&arg2->weakCount, -1) == 1) {
                void** vt2 = (void**)arg2->vptr;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(arg2);
            }
        }
    }
}

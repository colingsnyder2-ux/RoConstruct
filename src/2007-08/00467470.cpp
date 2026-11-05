// from server: 32% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void AddRef() {
        _InterlockedExchangeAdd((volatile long*)((char*)this + 4), 1);
    }
    void Release() {
        if (_InterlockedExchangeAdd((volatile long*)((char*)this + 4), -1) == 1) {
            (*(void(__thiscall**)(void*))*(void**)this)(this);
            if (_InterlockedExchangeAdd((volatile long*)((char*)this + 8), -1) == 1) {
                (*(void(__thiscall**)(void*))((*(void***)this)[2]))(this);
            }
        }
    }
};

struct SharedPtr {
    void* px;
    RefCounted* pi;
};

struct Obj {
    char pad0[0x28];
    SharedPtr sp28;
    SharedPtr sp30;
    char pad38[0x4];
    SharedPtr sp3c;
    char pad44[0x4];
};

extern "C" void __cdecl sub_40D550(SharedPtr* dst, SharedPtr* src);
extern "C" void* __cdecl sub_4109B0(void* p);
extern "C" void __cdecl sub_432530(void* p, void* q);
extern "C" void __cdecl sub_5595A0(void* p);
extern "C" void __cdecl sub_55C750(SharedPtr* src);

struct VCWorkspace {
    char pad0[0x28];
    SharedPtr sp28;
    SharedPtr sp30;
    char pad38[0x4];
    SharedPtr sp3c;
    char pad44[0x4];
    void func();
};

void VCWorkspace::func() {
    if (this->sp30.px == 0) {
        return;
    }

    SharedPtr tmp;
    tmp.px = this->sp30.px;
    tmp.pi = this->sp30.pi;
    if (tmp.pi) {
        tmp.pi->AddRef();
    }
    sub_40D550(&tmp, &tmp);

    void* p = sub_4109B0(this->sp30.px);
    if (p) {
        sub_432530((char*)p + 0xe8, &this->sp28);
    }

    void* q = *(void**)((char*)this->sp30.px + 0x188);
    if (q) {
        sub_432530((char*)q + 0x2d4, &this->sp30);
    }

    SharedPtr tmp2;
    tmp2.px = this->sp30.px;
    tmp2.pi = this->sp30.pi;
    if (tmp2.pi) {
        tmp2.pi->AddRef();
    }
    sub_55C750(&tmp2);

    this->sp3c.px = 0;
    RefCounted* old = (RefCounted*)this->sp3c.pi;
    this->sp3c.pi = 0;
    if (old) {
        old->Release();
    }

    this->sp30.px = 0;
    RefCounted* old2 = (RefCounted*)this->sp30.pi;
    this->sp30.pi = 0;
    if (old2) {
        old2->Release();
    }

    sub_5595A0(&tmp);
}

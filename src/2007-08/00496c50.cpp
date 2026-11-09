// from server: 43% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

struct SharedPtr {
    void* ptr;
    RefCounted* control;
};

struct String {
    char buf[0x1c];
};

extern "C" void* __stdcall sub_77e698(const char*);
extern "C" void __cdecl sub_412dc0(String*, const char*);
extern "C" void __cdecl sub_630b9e(String*, void*);
extern "C" void* __cdecl sub_40e330(void*);
extern "C" void __cdecl sub_402a60(void*, void*);
extern "C" void __cdecl sub_541630(void*, void*);
extern "C" void __cdecl sub_444710(void*, void*);
extern "C" void __cdecl sub_4925c0(void*, char);

struct VPlayers {
    char pad0[0x100];
    char field_100[0x38];
    void* field_138;
    RefCounted* field_13c;

    void func(void* a, void* b);
};

void VPlayers::func(void* a, void* b) {
    String str;
    SharedPtr sp;
    sp.ptr = 0;
    sp.control = 0;

    if (this->field_138 != 0) {
        sub_77e698("Local player already exists");
        sub_412dc0(&str, (const char*)&str);
        sub_630b9e(&str, (void*)0x8410c0);
    }

    void* r = sub_40e330(&sp.ptr);
    this->field_138 = *(void**)r;
    r = (char*)r + 4;
    sub_402a60(&this->field_13c, r);

    if (sp.ptr != 0) {
        RefCounted* c = sp.control;
        if (_InterlockedExchangeAdd(&c->refcount, -1) == 1) {
            void** vt = *(void***)c;
            void (*dtor)(void*) = (void (*)(void*))vt[1];
            dtor(c);
            if (_InterlockedExchangeAdd((volatile long*)((char*)c + 8), -1) == 1) {
                void** vt2 = *(void***)c;
                void (*dtor2)(void*) = (void (*)(void*))vt2[2];
                dtor2(c);
            }
        }
    }

    void* p = this->field_138;
    if (p != 0) {
        p = (char*)p + 4;
    } else {
        p = 0;
    }

    void* global = *(void**)0x8bde44;
    void** vt = *(void***)global;
    void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vt[2];
    fn(global, p, &sp);

    sub_541630(this->field_138, this);
    sub_444710(this, (void*)0x8be108);

    char result;
    if (this->field_138 != 0) {
        void* g2 = *(void**)0x8bde28;
        void** vt2 = *(void***)g2;
        void* arg = (char*)this->field_138 + 4;
        char (*fn2)(void*, void*) = (char (*)(void*, void*))vt2[1];
        result = fn2(g2, arg);
    } else {
        result = 0;
    }

    sub_4925c0(&this->field_100, result);

    void* out = *(void**)b;
    *(void**)out = this->field_138;
    RefCounted* ctrl = this->field_13c;
    *(RefCounted**)((char*)out + 4) = ctrl;
    if (ctrl != 0) {
        _InterlockedExchangeAdd(&ctrl->refcount, 1);
    }
}

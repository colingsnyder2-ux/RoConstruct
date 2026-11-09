// from server: 48% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBXName {
    void* rep;
};

struct RefCountedBase {
    void* vptr;
    long refCount;
    long weakRefCount;
};

struct CreatorBase {
    void* vptr;
};

struct FactoryProduct {
    char pad0[0x20];
    int field20;
    char pad24[0x64];
    void* field88;
    void* field8c;
    void* field90;
    char pad94[0x8];
    void* field9c;
    void* fielda0;
    void* fielda4;
};

extern "C" void __cdecl sub_49D670(void* out, void* in);
extern "C" void __cdecl sub_402A60(void* dst, void* src);
extern "C" void __cdecl sub_40D550(void* p);
extern "C" void __cdecl sub_40D990(void* out);
extern "C" void __cdecl sub_40E750(void* p);
extern "C" void __cdecl sub_541630(void* p, void* arg);
extern "C" void __cdecl sub_5595A0(void* p);
extern "C" void __cdecl sub_6302EC(void* p, int arg);

void FactoryProduct_ctor(FactoryProduct* self, void* arg1, void* arg2)
{
    void* local14;
    void* local18;
    void* local1c;
    void* local20;
    void* local24;
    void* local28;
    void* local2c;
    void* local30;
    void* local34;

    sub_49D670(&local14, arg1);
    self->field9c = *(void**)&local14;
    local14 = 0;
    sub_402A60(&self->fielda0, (char*)&local14 + 4);

    if (local18 != 0) {
        RefCountedBase* p = (RefCountedBase*)local18;
        if (_InterlockedExchangeAdd(&p->refCount, -1) == 1) {
            void** vt = *(void***)p;
            ((void (__thiscall*)(void*))vt[1])(p);
            if (_InterlockedExchangeAdd(&p->weakRefCount, -1) == 1) {
                void** vt2 = *(void***)p;
                ((void (__thiscall*)(void*))vt2[2])(p);
            }
        }
    }

    void* tmp = self->field9c;
    void* tmp2 = self->fielda0;
    local2c = tmp;
    local30 = tmp2;
    if (tmp2 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)tmp2 + 4), 1);
    }
    sub_40D550(&local2c);

    if (self->field8c != 0) {
        *(void**)((char*)self->field8c + 0xfc) = 0;
        sub_541630(self->field8c, 0);
        self->field8c = 0;
        void* p = self->field90;
        self->field90 = 0;
        if (p != 0) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
                void** vt = *(void***)p;
                ((void (__thiscall*)(void*))vt[1])(p);
                if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                    void** vt2 = *(void***)p;
                    ((void (__thiscall*)(void*))vt2[2])(p);
                }
            }
        }
    }

    self->field88 = arg2;
    if (arg1 != 0) {
        sub_40E750(arg1);
    } else {
        self->fielda4 = 0;
    }
    if (arg1 != 0) {
        self->fielda4 = (void*)0;
    }

    if (arg1 != 0) {
        sub_40D990(&local1c);
        self->field8c = *(void**)&local1c;
        sub_402A60(&self->field90, (char*)&local1c + 4);
        if (local20 != 0) {
            RefCountedBase* p = (RefCountedBase*)local20;
            if (_InterlockedExchangeAdd(&p->refCount, -1) == 1) {
                void** vt = *(void***)p;
                ((void (__thiscall*)(void*))vt[1])(p);
                if (_InterlockedExchangeAdd(&p->weakRefCount, -1) == 1) {
                    void** vt2 = *(void***)p;
                    ((void (__thiscall*)(void*))vt2[2])(p);
                }
            }
        }
        *(void**)((char*)self->field8c + 0xfc) = self;
        sub_541630(self->field8c, *(void**)((char*)arg1 + 0x1a8));
    }

    if (self->field20 != 0) {
        int flag = (self->fielda4 != 0) ? 1 : 0;
        sub_6302EC(self, flag);
    }

    sub_5595A0(&local24);
}

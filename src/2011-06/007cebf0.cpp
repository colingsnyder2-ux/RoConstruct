// from server: 15% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" char __cdecl sub_6C70F0();
extern "C" void __cdecl sub_7C8300();
extern "C" void* __cdecl sub_7C8980();
extern "C" void __cdecl sub_7C8B00();
extern "C" void __cdecl sub_7C94A0();
extern "C" void __cdecl sub_7CB2A0();
extern "C" void __cdecl sub_7CE640();
extern "C" void __cdecl sub_7CE9F0();
extern "C" void* __cdecl sub_80A05E(unsigned int);
extern "C" void __cdecl sub_86B640();

struct RefCounted {
    void** vptr;
    volatile long ref1;
    volatile long ref2;
};

struct S {
    char pad0[0xa4];
    void* fieldA4;
    char padA8[0x5c];
    char field104[0x4];
    char pad108[0x8];
    float field110;
    char pad114[0x90];
    void* field1A4;
    char pad1A8[0x34];
    void* field1DC;
    char pad1E0[0x90];
    void* field270;
    void func(int a, int b, int c, int d);
};

void S::func(int a, int b, int c, int d)
{
    void* local34 = 0;
    void* local38 = 0;
    int local3c = -1;
    void* local40 = 0;
    void* local44 = 0;
    void* local48 = 0;
    void* local4c = 0;
    void* local50 = 0;
    void* local54 = 0;

    if (sub_6C70F0()) {
        void* p = local48;
        local3c = -1;
        if (p) {
            RefCounted* r = (RefCounted*)p;
            if (_InterlockedExchangeAdd(&r->ref1, -1) == 1) {
                void** vt = (void**)r->vptr;
                ((void (__thiscall*)(void*))vt[1])(r);
                if (_InterlockedExchangeAdd(&r->ref2, -1) == 1) {
                    void** vt2 = (void**)r->vptr;
                    ((void (__thiscall*)(void*))vt2[2])(r);
                }
            }
        }
        return;
    }

    char bl;
    void* eax = *(void**)((char*)this + 0xa4);
    eax = *(void**)((char*)eax + 0x1dc);
    if (eax != 0 && *(void**)((char*)eax + 0x90) != local44) {
        bl = 1;
    } else {
        bl = 0;
    }

    int esi = 0;
    int eax2 = (int)local50;
    if (eax2 != 0) {
        eax2 -= 1;
        if (eax2 == 0) {
            esi = 2;
        } else {
            eax2 -= 1;
            if (eax2 == 0) {
                esi = 3;
            }
        }
    } else {
        esi = 1;
    }

    sub_7C8300();
    void* p2 = sub_80A05E(0x3c);
    local4c = p2;
    if (p2) {
        float f = *(float*)((char*)this + 0x110);
        char dl = (bl == 0) ? 1 : 0;
        int ecx = (unsigned char)dl;
        void* local24 = local44;
        void* local28 = local48;
        if (local48) {
            _InterlockedExchangeAdd((volatile long*)((char*)local48 + 4), 1);
        }
        void* r = sub_7C8980();
        esi = (int)r;
    } else {
        esi = 0;
    }

    sub_7C8B00();
    sub_86B640();
    sub_7C94A0();
    sub_7CE640();
    sub_7CB2A0();
    sub_7CE9F0();
    sub_7C94A0();

    if (local48) {
        RefCounted* r = (RefCounted*)local48;
        if (_InterlockedExchangeAdd(&r->ref1, -1) == 1) {
            void** vt = (void**)r->vptr;
            ((void (__thiscall*)(void*))vt[1])(r);
            if (_InterlockedExchangeAdd(&r->ref2, -1) == 1) {
                void** vt2 = (void**)r->vptr;
                ((void (__thiscall*)(void*))vt2[2])(r);
            }
        }
    }

    if (local48) {
        RefCounted* r = (RefCounted*)local48;
        if (_InterlockedExchangeAdd(&r->ref1, -1) == 1) {
            void** vt = (void**)r->vptr;
            ((void (__thiscall*)(void*))vt[1])(r);
            if (_InterlockedExchangeAdd(&r->ref2, -1) == 1) {
                void** vt2 = (void**)r->vptr;
                ((void (__thiscall*)(void*))vt2[2])(r);
            }
        }
    }
}

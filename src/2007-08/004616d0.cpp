// from server: 39% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);

struct RefCounted {
    void* vptr;
    long ref1;
    long ref2;
};

struct Inner {
    char pad[0x74];
};

struct Obj {
    char pad0[0x20];
    void* hwnd;
    char pad1[0xec - 0x24];
    char field_ec[4];
    char field_f0[4];
    char pad2[0x10c - 0xf4];
    char field_10c[4];
    char pad3[0x128 - 0x110];
    RefCounted* p128;
    RefCounted* p12c;
    void* p134;
    RefCounted* p138;
    void* p13c;
    RefCounted* p140;
};

extern "C" void __cdecl sub_402a60(void*, void*);
extern "C" void __cdecl sub_423240(void*, void*);
extern "C" void __cdecl sub_432530(void*, void*);
extern "C" void __cdecl sub_460840(void*, void*, void*);
extern "C" void __cdecl sub_461680(void*, void*);
extern "C" void __cdecl sub_49d670(void*, void*, void*);
extern "C" void __cdecl sub_725750(void*);
extern "C" void __cdecl sub_725770(void*);

void CScriptEditor_4616d0(Obj* self, void* arg1, void* arg2)
{
    RefCounted* local14 = 0;
    char local18 = 0;
    RefCounted* local20 = 0;
    RefCounted* local24 = 0;
    RefCounted* local28 = 0;
    RefCounted* local2c = 0;
    RefCounted* local30 = 0;
    RefCounted* local34 = 0;
    RefCounted* local38 = 0;

    if (self->p134 != 0) {
        RefCounted* ebp = self->p128;
        local14 = ebp;
        sub_725750(ebp);
        local18 = 1;

        if (self->p134 != 0) {
            sub_432530((char*)self->p134 + 0x74, self->field_ec);
        }
        if (self->p134 != 0) {
            sub_432530((char*)self->p134 + 0x8c, self->field_f0);
        }
        if (self->p13c != 0) {
            sub_432530((char*)self->p13c + 0x130, self->field_10c);
        }

        self->p134 = 0;

        RefCounted* edi = self->p138;
        self->p138 = 0;
        if (edi != 0) {
            if (_InterlockedExchangeAdd(&edi->ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))edi->vptr)(edi);
                if (_InterlockedExchangeAdd(&edi->ref2, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))edi->vptr)(edi);
                }
            }
        }

        self->p13c = 0;

        edi = self->p140;
        self->p140 = 0;
        if (edi != 0) {
            if (_InterlockedExchangeAdd(&edi->ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))edi->vptr)(edi);
                if (_InterlockedExchangeAdd(&edi->ref2, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))edi->vptr)(edi);
                }
            }
        }

        self->p128 = 0;

        edi = self->p12c;
        self->p12c = 0;
        if (edi != 0) {
            if (_InterlockedExchangeAdd(&edi->ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))edi->vptr)(edi);
                if (_InterlockedExchangeAdd(&edi->ref2, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))edi->vptr)(edi);
                }
            }
        }

        sub_725770(ebp);
    }

    if (arg1 != 0) {
        sub_460840(&local14, arg1, &local20);
        self->p128 = local20;
        sub_402a60(&self->p12c, &local24);

        RefCounted* ebp = local18 ? local14 : 0;
        if (ebp != 0) {
            if (_InterlockedExchangeAdd(&ebp->ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))ebp->vptr)(ebp);
                if (_InterlockedExchangeAdd(&ebp->ref2, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))ebp->vptr)(ebp);
                }
            }
        }

        self->p134 = arg1;
        sub_402a60(&self->p138, &local28);

        RefCounted* ebp2 = self->p128;
        local14 = ebp2;
        sub_725750(ebp2);
        local18 = 1;

        sub_461680(arg1, &local30);
        sub_49d670(&local34, &local30, &local38);
        self->p13c = local38;
        sub_402a60(&self->p140, &local38);

        if (local34 != 0) {
            RefCounted* edi = local34;
            if (_InterlockedExchangeAdd(&edi->ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))edi->vptr)(edi);
                if (_InterlockedExchangeAdd(&edi->ref2, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))edi->vptr)(edi);
                }
            }
        }

        if (self->p13c != 0) {
            sub_423240((char*)self->p13c + 0x130, self->field_10c);
        }
        if (self->p134 != 0) {
            sub_423240((char*)self->p134 + 0x8c, self->field_f0);
        }
        if (self->p134 != 0) {
            sub_423240((char*)self->p134 + 0x74, self->field_ec);
        }

        sub_725770(ebp2);
    }

    if (self->hwnd != 0) {
        PostMessageA(self->hwnd, 0x465, 0, 0);
    }

    if (local38 != 0) {
        RefCounted* esi = local38;
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))esi->vptr)(esi);
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))esi->vptr)(esi);
            }
        }
    }
}

// from server: 26% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    char pad[4];
    volatile long ref1;
    volatile long ref2;
    void Release();
};

void RefCounted::Release()
{
    if (_InterlockedExchangeAdd(&ref1, -1) == 1) {
        ((void (__thiscall*)(RefCounted*))vptr[1])(this);
        if (_InterlockedExchangeAdd(&ref2, -1) == 1)
            ((void (__thiscall*)(RefCounted*))vptr[2])(this);
    }
}

struct Obj {
    char pad0[0x8c];
    void* field8c;
    char pad90[0x0c];
    int field9c;
};

extern "C" void* __cdecl sub_719C7A(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_5F9B30(void*, void*);
extern "C" void __cdecl sub_5D1E50(void*, void*);
extern "C" void __cdecl sub_5D2990(void*, void*);
extern "C" void __cdecl sub_6247B0(void*);
extern "C" void* __cdecl sub_4B6D10(void*);
extern "C" void* __cdecl sub_4B6DB0(void*);
extern "C" void* __cdecl sub_4B6600(void*);
extern "C" void __cdecl sub_6685A0(void*, void*);
extern "C" void __cdecl sub_6685D0(void*, void*);

extern void* g_9dbe40;
extern void* g_9e9dbc;
extern void* g_9e9da4;
extern void* g_9ec3b0;
extern void* g_9ecc7c;
extern void* g_9e6fc8;

void __fastcall func(Obj* self, void* edx, void* arg1, void* arg2, char arg3)
{
    void* local8 = 0;
    void* localc = 0;
    void* local10 = 0;
    void* local14 = 0;
    void* local18 = 0;
    void* local1c = 0;
    void* local20 = 0;
    void* local24 = 0;
    void* local28 = 0;

    sub_5F9B30(&local8, &local28);
    void* ebx = local8;
    if (ebx == 0) {
        RefCounted* esi = (RefCounted*)localc;
        if (esi != 0) {
            if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))esi->vptr[1])(esi);
                if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1)
                    ((void (__thiscall*)(RefCounted*))esi->vptr[2])(esi);
            }
        }
        goto cleanup;
    }

    sub_5F9B30(&local10, &local28);
    void* esi2 = local10;
    if (esi2 == 0) {
        RefCounted* esi3 = (RefCounted*)local14;
        if (esi3 != 0) {
            if (_InterlockedExchangeAdd(&esi3->ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))esi3->vptr[1])(esi3);
                if (_InterlockedExchangeAdd(&esi3->ref2, -1) == 1)
                    ((void (__thiscall*)(RefCounted*))esi3->vptr[2])(esi3);
            }
        }
        RefCounted* esi4 = (RefCounted*)localc;
        if (esi4 != 0) {
            if (_InterlockedExchangeAdd(&esi4->ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))esi4->vptr[1])(esi4);
                if (_InterlockedExchangeAdd(&esi4->ref2, -1) == 1)
                    ((void (__thiscall*)(RefCounted*))esi4->vptr[2])(esi4);
            }
        }
        goto cleanup;
    }

    void* edi = self->field8c;
    if (edi != 0) {
        void* ebp = sub_719C7A(esi2, 0, &g_9dbe40, &g_9e9dbc, 0);
        if (ebp != 0) {
            void* eax = sub_4B6D10(edi);
            if (eax != 0)
                sub_6685A0(eax, ebp);
        } else {
            ebp = sub_719C7A(esi2, 0, &g_9dbe40, &g_9e9da4, 0);
            if (ebp != 0) {
                void* eax = sub_4B6D10(edi);
                if (eax != 0)
                    sub_6685D0(eax, ebp);
            } else {
                void* eax = sub_719C7A(esi2, 0, &g_9dbe40, &g_9ec3b0, 0);
                if (eax == 0) {
                    eax = sub_719C7A(esi2, 0, &g_9dbe40, &g_9ecc7c, 0);
                    if (eax != 0) {
                        eax = sub_719C7A(esi2, 0, &g_9dbe40, &g_9e6fc8, 0);
                        if (eax == 0)
                            sub_5D1E50(esi2, edi);
                    }
                } else {
                    sub_5D1E50(esi2, edi);
                }
            }
        }
    }

    {
        void* eax = sub_719C7A(esi2, 0, &g_9dbe40, &g_9e6fc8, 0);
        if (eax != 0 && self->field9c < 2) {
            void* eax2 = sub_4B6DB0(self);
            if (eax2 != 0)
                sub_5D1E50(esi2, eax2);
            if (arg3 != 0 && edi != 0) {
                sub_5D2990(esi2, &local1c);
                void* eax3 = *(void**)&local1c;
                sub_5D1E50(eax3, edi);
                sub_6247B0(&local1c);
            } else {
                void* eax4 = sub_4B6600(self);
                if (eax4 != 0) {
                    sub_5D2990(esi2, &local1c);
                    void* eax5 = *(void**)&local1c;
                    sub_5D1E50(eax5, eax4);
                    sub_6247B0(&local1c);
                }
            }
        }
    }

    {
        RefCounted* esi5 = (RefCounted*)local18;
        if (esi5 != 0) {
            if (_InterlockedExchangeAdd(&esi5->ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))esi5->vptr[1])(esi5);
                if (_InterlockedExchangeAdd(&esi5->ref2, -1) == 1)
                    ((void (__thiscall*)(RefCounted*))esi5->vptr[2])(esi5);
            }
        }
    }

    {
        RefCounted* esi6 = (RefCounted*)localc;
        if (esi6 != 0) {
            if (_InterlockedExchangeAdd(&esi6->ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))esi6->vptr[1])(esi6);
                if (_InterlockedExchangeAdd(&esi6->ref2, -1) == 1)
                    ((void (__thiscall*)(RefCounted*))esi6->vptr[2])(esi6);
            }
        }
    }

cleanup:
    {
        RefCounted* eax = (RefCounted*)local24;
        if (eax != 0) {
            if (_InterlockedExchangeAdd(&eax->ref2, -1) == 1)
                ((void (__thiscall*)(RefCounted*))eax->vptr[2])(eax);
        }
    }
    {
        RefCounted* eax = (RefCounted*)local28;
        if (eax != 0) {
            if (_InterlockedExchangeAdd(&eax->ref2, -1) == 1)
                ((void (__thiscall*)(RefCounted*))eax->vptr[2])(eax);
        }
    }
}

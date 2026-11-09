// from server: 33% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" void __stdcall SetEvent(void*);
extern "C" void __cdecl _invalid_parameter_noinfo();

struct RefCounted {
    long refcount;
    char pad1[4];
    long weakref;
    char pad2[4];
};

struct Inner {
    char pad0[0x10];
    RefCounted rc;
    char pad3[0x0c];
    void* field_20;
    char pad4[0x14];
    void* field_38;
};

struct Outer {
    char pad0[0x10];
    Inner* inner;
};

extern "C" void __cdecl sub_401690(void*, void*);
extern "C" void* __cdecl sub_529740();
extern "C" void __cdecl sub_418840(void*);
extern "C" void __cdecl sub_52f9e0(void*, void*, void*);
extern "C" void* __cdecl sub_7a79a0(unsigned int);
extern "C" void* __cdecl sub_549660(void*, void*, void*);
extern "C" void* __cdecl sub_531a00(void*, void*);
extern "C" void __cdecl sub_486d20(void*, void*);
extern "C" void* __cdecl sub_410cb0();

extern void* g_9ea90c;
extern void* g_9ea398;
extern char g_c08b98;
extern char g_5297a0;

void* __fastcall func(Outer* self, void* unused, void* a2, void* a3)
{
    sub_401690(&g_5297a0, &g_c08b98);
    void* edi = sub_529740();
    Inner* esi = (Inner*)((char*)edi + 0x10);
    sub_418840(esi);

    float* f = (float*)a3;
    float x = f[0];
    float y = f[1];
    float z = f[2];

    float local[3];
    local[0] = x;
    local[1] = y;
    local[2] = z;

    void* local2 = 0;
    sub_52f9e0((char*)edi + 0x20, &local2, local);

    void* eax = *(void**)((char*)edi + 0x20 + 0x18);
    void* ebx = local2;
    void* saved = eax;

    eax = *(void**)((char*)edi + 0x20);

    if (ebx != 0) {
        if (ebx == eax) {
            goto skip;
        }
    }
    ((void (__stdcall*)())g_9ea90c)();
skip:
    {
        void* ecx = local2;
        if (ecx != saved) {
            goto other;
        }
    }

    {
        void* p = sub_7a79a0(0x8c);
        void* ebx2;
        if (p != 0) {
            ebx2 = sub_549660(p, a2, a3);
        } else {
            ebx2 = 0;
        }
        void* r = sub_531a00((char*)edi + 0x20, local);
        sub_486d20(r, ebx2);

        if (--esi->rc.refcount == 0) {
            esi->rc.weakref = 0;
            long old = _InterlockedExchangeAdd(&esi->rc.weakref, (long)0x80000000);
            if (!(old & 0x40000000) && old > (long)0x80000000) {
                if (!_interlockedbittestandset(&esi->rc.weakref, 0x1e)) {
                    void* e = sub_410cb0();
                    ((void (__stdcall*)(void*))g_9ea398)(e);
                }
            }
        }
        return ebx2;
    }

other:
    if (ebx == 0) {
        ((void (__stdcall*)())g_9ea90c)();
        void* ecx = local2;
        if (ecx == *(void**)((char*)ebx + 0x18)) {
            ((void (__stdcall*)())g_9ea90c)();
        }
        void* edx = local2;
        void* edi2 = *(void**)((char*)edx + 0x1c);

        if (--esi->rc.refcount == 0) {
            esi->rc.weakref = 0;
            long old = _InterlockedExchangeAdd(&esi->rc.weakref, (long)0x80000000);
            if (!(old & 0x40000000) && old > (long)0x80000000) {
                if (!_interlockedbittestandset(&esi->rc.weakref, 0x1e)) {
                    void* e = sub_410cb0();
                    ((void (__stdcall*)(void*))g_9ea398)(e);
                }
            }
        }
        return edi2;
    }
    ebx = *(void**)ebx;
    goto other;
}

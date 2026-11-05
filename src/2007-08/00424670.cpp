// from server: 36% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refCount;
};

struct Name;

struct Creator {
    void* vptr;
    char pad[0x0c];
    void* field10;
    void* field14;
    char pad2[0x14];
    void* field2c;
    char pad3[0x14];
    void* field44;
    char pad4[0x14];
    void* field5c;
    char pad5[0x14];
    void* field74;
    char pad6[0x14];
    void* field8c;
};

struct Pair {
    void* first;
    void* second;
};

extern "C" void __cdecl sub_4245E0(void* out, void* in);

struct FactoryProduct {
    void* field0;
    void* field4;
};

void __stdcall sub_424670(void* result, void* arg);

void __stdcall sub_424670(void* result, void* arg)
{
    Pair local;
    local.first = 0;
    local.second = 0;

    sub_4245E0(&local, arg);

    *(void**)result = local.first;
    void* p = local.second;
    *(void**)((char*)result + 4) = p;
    if (p != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
    }

    void* esi = local.first;
    if (esi != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
            void** vt = *(void***)esi;
            ((void (__stdcall*)(void*))vt[1])(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                void** vt2 = *(void***)esi;
                ((void (__stdcall*)(void*))vt2[2])(esi);
            }
        }
    }
}

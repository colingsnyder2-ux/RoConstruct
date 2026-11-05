// from server: 33% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    long refCount;
};

struct VehicleController {
    char pad_0[0x34];
    void* field_34;
    char pad_38[0x48];
    RefCounted* field_80;
    char pad_84[0x4];
    void* field_88;

    void __thiscall sub_7A38F0(int arg);
};

extern "C" void* __cdecl sub_7A1200(void* thisptr);
extern "C" void __cdecl sub_439330(void* thisptr, void** outPtr);
extern "C" void __cdecl sub_7A50C0(void* thisptr, char* outBuffer);
extern "C" void __cdecl sub_8E4CE0(void* thisptr, int value);
extern "C" void __cdecl sub_8E4D30(void* thisptr, int value);
extern "C" char __cdecl sub_7A0AE0(void* thisptr, int value);
extern "C" void __cdecl sub_7A3870(void* thisptr, int value, int arg);
extern "C" void* __cdecl sub_8E2180(void* thisptr);
extern "C" void __cdecl sub_79DB30(void* thisptr, int value);
extern "C" void __cdecl sub_972290(int value, int arg);

void __thiscall VehicleController::sub_7A38F0(int arg) {
    void* ebp = sub_7A1200(this->field_80);
    if (!ebp)
        return;

    void* edi = 0;
    sub_439330(&this->field_34, &edi);
    if (!edi) {
        extern char byte_E580B3;
        extern int dword_E5809C;
        if (byte_E580B3) {
            if (dword_E5809C) {
                typedef int (__cdecl *FnType)(int, int, int);
                FnType fn = (FnType)dword_E5809C;
                if (fn(0x191, 0xBB4F60, 0xB460CC))
                    goto LABEL_RELEASE_ESI;
            }
            sub_972290(byte_E580B3, 0xBB5200);
        }
    LABEL_RELEASE_ESI:
        void* esi = this->field_88;
        if (esi) {
            if (_InterlockedExchangeAdd(&((RefCounted*)esi)->refCount, -1) == 1) {
                void* vtable = *(void**)esi;
                void (__thiscall *dtor)(void*) = (void (__thiscall*)(void*))*(int*)((char*)vtable + 4);
                dtor(esi);
                if (_InterlockedExchangeAdd((long*)((char*)esi + 8), -1) == 1) {
                    void (__thiscall *deleteFn)(void*) = (void (__thiscall*)(void*))*(int*)((char*)vtable + 8);
                    deleteFn(esi);
                }
            }
        }
        return;
    }

    char buffer[16] = {0};
    sub_7A50C0(ebp, buffer);

    int ecx_val;
    if (buffer[0])
        ecx_val = 1;
    else
        ecx_val = -((signed char)buffer[1] != 0);

    int eax_val;
    if (buffer[4])
        eax_val = 1;
    else
        eax_val = -((signed char)buffer[5] != 0);

    int edx = eax_val + ecx_val;

    int ecx_val2;
    if (buffer[2])
        ecx_val2 = 1;
    else
        ecx_val2 = -((signed char)buffer[3] != 0);

    int eax_val2;
    if (buffer[6])
        eax_val2 = 1;
    else
        eax_val2 = -((signed char)buffer[7] != 0);

    int esi_val = eax_val2 + ecx_val2;

    sub_8E4CE0(edi, edx);
    sub_8E4D30(edi, -esi_val);

    void* esi = this->field_88;
    if (sub_7A0AE0(esi, 0x20)) {
        int value = *(int*)((char*)&arg + 0x16);
        sub_7A3870(esi, 0x20, value);
    } else {
        void* eax = sub_8E2180(edi);
        if (eax) {
            int value = *(int*)((char*)&arg + 0x16);
            sub_79DB30(eax, value);
        }
    }

    if (esi) {
        if (_InterlockedExchangeAdd(&((RefCounted*)esi)->refCount, -1) == 1) {
            void* vtable = *(void**)esi;
            void (__thiscall *dtor)(void*) = (void (__thiscall*)(void*))*(int*)((char*)vtable + 4);
            dtor(esi);
            if (_InterlockedExchangeAdd((long*)((char*)esi + 8), -1) == 1) {
                void (__thiscall *deleteFn)(void*) = (void (__thiscall*)(void*))*(int*)((char*)vtable + 8);
                deleteFn(esi);
            }
        }
    }
}

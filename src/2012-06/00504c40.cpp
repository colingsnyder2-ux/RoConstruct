// from server: 51% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    int vptr;
    long refCount;
};

struct SmartPtr {
    RefCounted* ptr;
    long unk;
};

struct Creator {
    virtual SmartPtr* create(SmartPtr* out, void* arg);
};

extern "C" void __cdecl sub_504BC0(SmartPtr*);
extern "C" void __cdecl sub_972290(const char*, int);

extern int dword_E1D518;
extern int dword_E5809C;
extern char byte_E580B3;

SmartPtr* Creator::create(SmartPtr* out, void* arg) {
    SmartPtr temp;
    temp.ptr = 0;
    temp.unk = 0;

    if (byte_E580B3) {
        if (dword_E1D518 != 0x29A) {
            int (__cdecl* callback)(int, int, int) = (int (__cdecl*)(int, int, int))dword_E5809C;
            if (callback) {
                if (callback(0xCA, 0xB64958, 0xB42F90)) {
                    goto LABEL_RETURN;
                }
            }
            sub_972290("wasConstructed()", byte_E580B3);
        }
    }

LABEL_RETURN:
    sub_504BC0(&temp);

    RefCounted* obj = temp.ptr;
    RefCounted* target = obj ? (RefCounted*)((char*)obj + 0x18) : 0;

    out->ptr = target;
    out->unk = obj ? obj->refCount : 0;

    if (obj) {
        _InterlockedExchangeAdd(&obj->refCount, 1);
    }

    void* esi = arg;
    int guard = 0;
    int flag = 1;

    if (esi) {
        long* ref = (long*)((char*)esi + 4);
        if (_InterlockedExchangeAdd(ref, -1) == 1) {
            int (__thiscall* dtor1)(void*) = *(int (__thiscall**)(void*))esi;
            dtor1(esi);
            long* ref2 = (long*)((char*)esi + 8);
            if (_InterlockedExchangeAdd(ref2, -1) == 1) {
                int (__thiscall* dtor2)(void*) = *(int (__thiscall**)(void*))((char*)esi + 4);
                dtor2(esi);
            }
        }
    }

    return out;
}

// from server: 23% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    int refCount;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct VDialogRoot {
    void EventDesc(int a1, int a2, int a3, int a4);
};

void __stdcall sub_52ECE0(int, int, int, int, int, int, int);
void __stdcall sub_683570(int*);
void __stdcall sub_8C9AC0(void*, int, int, int);

void VDialogRoot::EventDesc(int a1, int a2, int a3, int a4) {
    int v12 = 0;
    unsigned char v13 = *(unsigned char*)0xE53A31;
    int v14 = a1;
    int v15 = *(unsigned char*)0xE539A1;
    int v16 = 0;
    int v17 = 0;
    int v18 = 0;
    int v19 = 0;
    int v20 = v14;
    int v21 = a2;
    int v22 = a3;
    int v23 = 1;
    int v24 = 0x6827E0;
    int v25 = 0;
    if (v22) {
        v25 = v22 + 4;
        v16 = 1;
        _InterlockedExchangeAdd((volatile long*)v25, 1);
    }
    sub_52ECE0(v16, v24, v17, v18, v19, v20, v21);
    int v26 = 0;
    sub_683570(&v26);
    int v27 = a4;
    int v28 = a3;
    int v29 = a2;
    int v30 = 2;
    sub_8C9AC0(this, v29, v28, v27);
    int v31 = v26;
    v23 = 1;
    v30 = 1;
    if (v31) {
        int v32 = *(int*)v31;
        if (v32) {
            int v33 = 0;
            int v34 = 2;
            int v35 = v33;
            int v36 = v33;
            ((void(__stdcall*)(int, int, int))v32)(v34, v35, v36);
        }
        v26 = 0;
    }
    int v37 = a1;
    v30 = 0;
    if (v37) {
        int v38 = v37 + 4;
        if (_InterlockedExchangeAdd((volatile long*)v38, -1) == 1) {
            int v39 = *(int*)v37;
            int v40 = *(int*)(v39 + 4);
            ((void(__thiscall*)(int))v40)(v37);
            int v41 = v37 + 8;
            if (_InterlockedExchangeAdd((volatile long*)v41, -1) == 1) {
                int v42 = *(int*)v37;
                int v43 = *(int*)(v42 + 8);
                ((void(__thiscall*)(int))v43)(v37);
            }
        }
    }
}

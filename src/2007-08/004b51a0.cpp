// from server: 18% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ClientProxy {
    char pad0[0xe8];
    char field_e8[0x1d6c - 0xe8];
    char field_1d6c[0x1d70 - 0x1d6c];
    char field_1d70[0x1d74 - 0x1d70];
    char field_1d74[0x1d8c - 0x1d74];
    int field_1d8c;
    char field_1d90[0x1e14 - 0x1d90];
    void* field_1e14;
    void Method(int, int);
};

void ClientProxy::Method(int a, int b) {
    char* self = (char*)this;
    void* local = 0;
    if (a) {
        int r = ((int (__thiscall*)(int))0x4b0620)(a);
        if (r) {
            char tmp[8];
            ((void (__thiscall*)(char*, int))0x49d670)(tmp, r);
            ((void (__thiscall*)(void*, char*))0x4abc80)(this, tmp);
        }
    }
    ((void (__thiscall*)(void*))0x4ab9a0)(this);
    ((void (__thiscall*)(void*))0x42bad0)(self + 0x1d90);
    int ebp = *(int*)(self + 0x1d74);
    if (*(unsigned*)(self + 0x1d70) > (unsigned)ebp) {
        ((void (__stdcall*)())0x77e6d8)();
    }
    char* esi = self + 0x1d6c;
    int edi = *(int*)(esi + 4);
    if ((unsigned)edi > *(unsigned*)(esi + 8)) {
        ((void (__stdcall*)())0x77e6d8)();
    }
    char tmp2[8];
    ((void (__thiscall*)(char*, char*, int, char*, int))0x5cdca0)(esi, tmp2, edi, esi, ebp);
    int arg1 = *(int*)(self + 0x1d70);
    int arg2 = *(int*)(self + 0x1d74);
    ((void (__thiscall*)(void*, int, int))0x57aa50)(this, arg1, arg2);
    int v;
    if (b) {
        v = ((int (__thiscall*)(int))0x454990)(b);
    } else {
        v = 0;
    }
    ((void (__thiscall*)(void*, int))0x4b3ba0)(this, v);
    int v2;
    if (b) {
        v2 = ((int (__thiscall*)(int))0x4b0720)(b);
    } else {
        v2 = 0;
    }
    *(int*)(self + 0x1d8c) = v2;
    ((void (__thiscall*)(char*, int*))0x464ec0)(esi, &v2);
    int v3;
    if (b) {
        v3 = ((int (__thiscall*)(int))0x48cbe0)(b);
    } else {
        v3 = 0;
    }
    ((void (__thiscall*)(char*, int*))0x464ec0)(esi, &v3);
    int v4;
    if (b) {
        v4 = ((int (__thiscall*)(int))0x4b0820)(b);
    } else {
        v4 = 0;
    }
    ((void (__thiscall*)(char*, int*))0x464ec0)(esi, &v4);
    int v5;
    if (b) {
        v5 = ((int (__thiscall*)(int))0x40e750)(b);
    } else {
        v5 = 0;
    }
    *(int*)(self + 0x1d8c) = v5;
    ((void (__thiscall*)(char*, int*))0x464ec0)(esi, &v5);
    int v6;
    if (b) {
        v6 = ((int (__thiscall*)(int))0x4b0620)(b);
    } else {
        v6 = 0;
    }
    ((void (__thiscall*)(char*, int*))0x464ec0)(esi, &v6);
    int v7;
    if (b) {
        v7 = ((int (__thiscall*)(int))0x4b0920)(b);
    } else {
        v7 = 0;
    }
    ((void (__thiscall*)(char*, int*))0x464ec0)(esi, &v7);
    if (b) {
        int r = ((int (__thiscall*)(int))0x4b0620)(b);
        if (r) {
            char tmp3[8];
            ((void (__thiscall*)(char*, int))0x49d670)(tmp3, r);
            ((void (__thiscall*)(void*, char*))0x4b20f0)(this, tmp3);
            void* p = ((void* (__cdecl*)(int))0x62fef6)(0x10);
            if (p) {
                char tmp4[8];
                ((void (__thiscall*)(char*, int))0x49d670)(tmp4, r);
                ((void (__thiscall*)(void*, void*, char*))0x4aa410)(p, this, tmp4);
            }
        }
    }
    ((void (__thiscall*)(void*))0x4b3100)(this);
    if (!b) {
        void* p = *(void**)(self + 0x1e14);
        if (p) {
            void** vt = *(void***)p;
            typedef void (__thiscall *Fn)(void*, void*);
            Fn fn = (Fn)vt[0xec/4];
            fn(p, self + 0xe8);
            *(void**)(self + 0x1e14) = 0;
        }
        ((void (__thiscall*)(void*))0x4ac060)(this);
    }
}

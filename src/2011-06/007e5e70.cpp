// from server: 7% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" {
    void* __cdecl sub_6084F0(void*);
    void __cdecl sub_7E1D90(void*, void*, void*, void*, void*);
    void __cdecl sub_80A058(void*);
    void* __cdecl sub_66C780(void*);
    void __cdecl sub_60ABD0(void*, void*);
    void __cdecl sub_761340(void*, void*);
    void* __cdecl sub_541450();
    void __cdecl sub_540050(void*, void*);
    void __cdecl sub_4F5260(void*);
}

struct AdvMoveToolBase {
    char pad0[0x1c];
    void* field1c;
    bool func(void* a, void* b, void* c);
};

bool AdvMoveToolBase::func(void* a, void* b, void* c) {
    void* local18 = field1c;
    void* local1c = 0;
    void* local20 = 0;
    void* local40 = 0;
    void* local44 = 0;
    void* local48 = 0;
    void* local3c = 0;
    float local24[3];
    void* local4c[9];
    float local70[3];
    float local8c, local94, local10;

    void* r = sub_6084F0(&local18);
    void* ebp = *(void**)((char*)r + 0x94);
    ebp = *(void**)((char*)ebp + 8);
    r = sub_6084F0(&local18);
    void* eax = *(void**)((char*)r + 0x94);
    eax = *(void**)((char*)eax + 4);
    sub_7E1D90(&local18, eax, ebp, (void*)0x7e1be0, &local3c);

    void* end = local48;
    void* begin = local44;
    int count = (int)((char*)end - (char*)begin) >> 2;

    if (count == 0) {
        if (begin) sub_80A058(begin);
        void* esi = local20;
        local40 = 0;
        local44 = 0;
        local48 = 0;
        if (esi) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
                void** vt = *(void***)esi;
                ((void(__thiscall*)(void*))vt[1])(esi);
                if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                    void** vt2 = *(void***)esi;
                    ((void(__thiscall*)(void*))vt2[2])(esi);
                }
            }
        }
        return false;
    }

    if (c) *(char*)c = 0;

    if (count == 1) {
        void* eax2 = *(void**)begin;
        void* esi = sub_66C780(eax2);
        if (esi == 0) {
            if (local40) sub_80A058(local40);
            local40 = 0;
            local44 = 0;
            local48 = 0;
            sub_4F5260(&local18);
            return false;
        }
        void* ecx2 = *(void**)((char*)esi + 0x168);
        sub_60ABD0(ecx2, local24);
        float* f = local24;
        float* out = (float*)c;
        out[0] = f[0];
        out[1] = f[1];
        out[2] = f[2];
        out[3] = f[3];
        out[4] = f[4];
        out[5] = f[5];

        void* eax3 = *(void**)((char*)esi + 0x94);
        void* ecx3 = *(void**)((char*)eax3 + 4);
        void* edx3 = *(void**)((char*)ecx3 + (int)esi + 0x94);
        void* edx4 = *(void**)edx3;
        void* ecx4 = (void*)((char*)ecx3 + (int)esi + 0x94);
        void* eax4 = local4c;
        ((void(__thiscall*)(void*, void*))edx4)(ecx4, eax4);

        void* dst = b;
        void* src = eax4;
        for (int i = 0; i < 9; i++) ((int*)dst)[i] = ((int*)src)[i];
        ((float*)dst)[9] = ((float*)src)[9];
        ((float*)dst)[10] = ((float*)src)[10];
        ((float*)dst)[11] = ((float*)src)[11];

        if (c) *(char*)c = 1;

        if (local40) sub_80A058(local40);
        local40 = 0;
        local44 = 0;
        local48 = 0;
        sub_4F5260(&local18);
        return true;
    }

    sub_761340(&local18, &local3c);
    float* f = local24;
    float* out = (float*)c;
    out[0] = f[0];
    out[1] = f[1];
    out[2] = f[2];
    out[3] = f[3];
    out[4] = f[4];
    out[5] = f[5];

    float xmm3 = *(float*)0xa75b68;
    float v0 = (out[0] + out[3]) * xmm3;
    float v1 = (out[4] + out[1]) * xmm3;
    float v2 = (out[5] + out[2]) * xmm3;
    local8c = v0;
    local94 = v1;
    local10 = v2;
    local24[0] = v0;
    local24[1] = v1;
    local24[2] = v2;

    void* p = sub_541450();
    sub_540050(local4c, p);

    local70[0] = local24[0];
    local70[1] = local24[1];
    local70[2] = local24[2];

    void* dst = b;
    void* src = local4c;
    for (int i = 0; i < 9; i++) ((int*)dst)[i] = ((int*)src)[i];
    ((float*)dst)[9] = local8c;
    ((float*)dst)[10] = local94;
    ((float*)dst)[11] = local10;

    if (local40) sub_80A058(local40);
    void* esi2 = local20;
    local40 = 0;
    local44 = 0;
    local48 = 0;
    if (esi2) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi2 + 4), -1) == 1) {
            void** vt = *(void***)esi2;
            ((void(__thiscall*)(void*))vt[1])(esi2);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi2 + 8), -1) == 1) {
                void** vt2 = *(void***)esi2;
                ((void(__thiscall*)(void*))vt2[2])(esi2);
            }
        }
    }
    return true;
}

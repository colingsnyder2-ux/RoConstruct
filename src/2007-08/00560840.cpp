// from server: 32% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct Selection;

struct FilteredSelection {
    char pad0[4];
    char flag4;
    char pad5[3];
    void* field8;
    void* fieldC;
    void addFilteredSelection(Selection* sel);
};

struct Selection {
    char pad0[8];
    void* field8;
    void* fieldC;
};

extern "C" void* __cdecl sub_5BFAB0(void*, void*);
extern "C" void* __cdecl sub_5BF780(void*, void*);
extern "C" void* __cdecl sub_630D36(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_4A7E00(void*, void*);
extern "C" void __cdecl sub_4A8040(void*, void*);
extern "C" void __cdecl sub_564880(void*, void*);

void FilteredSelection::addFilteredSelection(Selection* sel)
{
    void* local10;
    void* local14;
    void* local18;
    void* local1C;
    void* local20;
    void* local24;
    void* local28;
    void* local2C;
    void* local30;

    void* p = sub_5BFAB0((char*)sel->fieldC + 8, &local14);
    void* ecx_val = *(void**)p;
    void* edx_val = *(void**)((char*)p + 4);

    void* eax_val = *(void**)((char*)this + 8);
    void* ebp_val = *(void**)((char*)eax_val + 0x10);

    local18 = 0;
    local1C = (char*)this + 4;
    local20 = ecx_val;
    local24 = edx_val;

    if (*(unsigned int*)((char*)eax_val + 0xC) > (unsigned int)ebp_val) {
        _invalid_parameter_noinfo();
        ecx_val = local20;
    }

    if (ecx_val != 0 && ecx_val == (char*)eax_val + 8) {
        // ok
    } else {
        _invalid_parameter_noinfo();
        ecx_val = local20;
    }

    if (local24 != ebp_val) {
        if (ecx_val == 0) {
            _invalid_parameter_noinfo();
            ecx_val = local20;
        }
        if ((unsigned int)local24 >= *(unsigned int*)((char*)ecx_val + 8)) {
            _invalid_parameter_noinfo();
        }
        void* v = *(void**)local24;
        void* r = sub_630D36(v, 0, (void*)0x887174, (void*)0x887e68, 0);
        if (r != 0) {
            void* ebp2 = local24;
            void* edx2 = local20;
            if ((unsigned int)ebp2 >= *(unsigned int*)((char*)edx2 + 8)) {
                _invalid_parameter_noinfo();
            }
            void* eax2 = *(void**)ebp2;
            local14 = (char*)this + 4;
            local10 = eax2;
            sub_4A7E00(&local10, &local14);
            if (*(char*)((char*)this + 4) != (char)r) {
                void* edi2 = *(void**)((char*)this + 8);
                sub_5BF780(&local10, &local18);
                sub_564880(edi2, &local18);
                sub_5BF780(&local10, &local20);
                sub_4A8040(&local20, &local1C);
                void* ebx2 = *(void**)((char*)this + 0xC);
                sub_5BF780(&local10, &local18);
                sub_564880(ebx2, &local18);
            }
        }
    }

    void* esi2 = local28;
    local30 = (void*)0xFFFFFFFF;
    if (esi2 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi2 + 4), -1) == 1) {
            void* vt = *(void**)esi2;
            void (*fn)(void*) = *(void (**)(void*))((char*)vt + 4);
            fn(esi2);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi2 + 8), -1) == 1) {
                void* vt2 = *(void**)esi2;
                void (*fn2)(void*) = *(void (**)(void*))((char*)vt2 + 8);
                fn2(esi2);
            }
        }
    }
}

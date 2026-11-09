// from server: 40% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" const char* __stdcall c_str_helper(void*);
extern "C" void* __stdcall sub_444B70(void*);
extern "C" void* __stdcall sub_4433E0(void*, void*);
extern "C" void* __stdcall sub_630634(void*, int, int, int, int, int, int, int, int, int);
extern "C" void* __stdcall sub_63063A(void*, void*, int, int, int, int, int, int);
extern "C" void __stdcall sub_434C70(void*, void*, void*);
extern "C" void* __stdcall sub_77E6A8(void*);

struct CMemberTreeView {
    char pad[0xa8];
    char field_a8;
    char pad2[3];
    int field_ac;
    void func_434f60(void* arg);
};

void CMemberTreeView::func_434f60(void* arg)
{
    void* local_14 = 0;
    int local_18 = 0;
    void* local_1c = 0;
    int local_20 = -1;
    void* ebx = arg;
    void* ebp;
    void* esi;
    void* eax;

    if (this->field_a8 == 0) {
        if (*(int*)((char*)ebx + 0xc) != this->field_ac) {
            goto cleanup;
        }
    }

    sub_444B70(&local_14);
    eax = *(void**)local_14;
    local_18 = 0;
    ebp = sub_4433E0(eax, ebx);

    if (local_14 != 0) {
        esi = local_14;
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
            eax = *(void**)esi;
            void (*fn)(void*) = *(void(**)(void*))((char*)eax + 4);
            fn(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                eax = *(void**)esi;
                void (*fn2)(void*) = *(void(**)(void*))((char*)eax + 8);
                fn2(esi);
            }
        }
    }

    if (ebp != 0) {
        if (*(char*)((char*)ebp + 0xe8) == 0) {
            goto cleanup;
        }
    }

    eax = *(void**)((char*)ebx + 4);
    void* hdc = sub_77E6A8((char*)eax + 4);
    void* result = sub_630634(this, (int)hdc, 0x23, 8, 8, 0, 0, 0, 0xffff0000, 0xffff0002);
    esi = result;
    sub_63063A(this, esi, 4, 0, 0, 0, 0, 0);
    sub_434C70(this, esi, ebp);

cleanup:
    return;
}

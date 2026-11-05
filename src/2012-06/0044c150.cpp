// from server: 36% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall sub_427720(void*);
extern "C" void* __stdcall sub_427BA0(void*, void*);
extern "C" bool __stdcall sub_427460(void*);
extern "C" void __stdcall sub_44B120(void*, void*, void*);
extern "C" void* __stdcall sub_464040(void*, void*);
extern "C" void* __stdcall sub_982BF4(void*, int, int, int, int, int, int, int, int, int);
extern "C" void __stdcall sub_982A62(void*, void*, int, int, int, int, int, int, void*);
extern "C" void __stdcall sub_449880(void*, void*, void*, void*);

struct CMemberTreeView {
    char pad_000[0xa8];
    char field_a8;
    char pad_a9[3];
    int field_ac;
    void func_44c150(void* arg);
};

void CMemberTreeView::func_44c150(void* arg)
{
    char* esi = (char*)arg;
    if (field_a8 == 0) {
        if (*(int*)(esi + 0x14) != field_ac)
            return;
    }

    void* local18 = 0;
    void* p = sub_427720(&local18);
    void* eax = *(void**)p;
    int ebp = 0;
    void* ebx = sub_464040(eax, esi);

    void* local1c = local18;
    if (local1c != 0) {
        void* edi = local1c;
        volatile long* ref1 = (volatile long*)((char*)edi + 4);
        if (_InterlockedExchangeAdd(ref1, -1) == 1) {
            void** vt = *(void***)edi;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(edi);
            volatile long* ref2 = (volatile long*)((char*)edi + 8);
            if (_InterlockedExchangeAdd(ref2, -1) == 1) {
                void** vt2 = *(void***)edi;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(edi);
            }
        }
    }

    if (ebx != 0) {
        void* r = sub_427BA0(ebx, esi);
        if (!sub_427460(r))
            return;
    }

    char* str = (char*)(*(int*)(esi + 0xc) + 4);
    char local30[0x1c];
    typedef void (__stdcall *FnCtor)(void*, const char*);
    typedef void (__stdcall *FnAppend)(void*, const char*);
    typedef void (__stdcall *FnDtor)(void*);
    ((FnCtor)0xb22644)(local30, str);
    ((FnAppend)0xb2265c)(local30, (const char*)0xb52f68);

    int local2c = 0;
    void* ebp2 = &local2c;
    int ecx_val = *(int*)(esi + 0x24);
    void* ebx2 = *(void**)ecx_val;

    void* tmp[3];
    tmp[0] = (void*)0x44b200;
    tmp[1] = &local30;
    tmp[2] = ebp2;
    sub_44B120(tmp, ebx2, (void*)ecx_val);

    ((FnAppend)0xb2265c)(ebp2, (const char*)0xb52f64);

    int eax2 = *(int*)(esi + 0x18);
    int edi;
    if (eax2 == 0)
        edi = 4;
    else if (eax2 == 1)
        edi = 0xd;
    else
        edi = 5;

    ((FnDtor)0xb22640)(&local2c);

    void* self = this;
    void* r2 = sub_982BF4(self, 0x23, eax2, edi, edi, 0, 0, 0, 0xffff0000, 0xffff0002);
    void* edi2 = r2;
    sub_982A62(self, edi2, 4, 0, 0, 0, 0, 0, esi);
    sub_449880(self, edi2, ebx, esi);

    ((FnDtor)0xb2263c)(&local2c);
}

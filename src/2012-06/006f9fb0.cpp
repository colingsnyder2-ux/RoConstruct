// from server: 47% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_5C9FE8(int, const char*, int);
extern "C" void __cdecl sub_6F28B0();
extern "C" void* __cdecl sub_41A3C0();
extern "C" void __cdecl sub_42B340(void*, void*);
extern "C" void __cdecl sub_42B2E0(void*, void*);
extern "C" void* __cdecl sub_6F9590(void*, void*, void*, void*);
extern "C" void __cdecl sub_6FC930(void*, void*);
extern "C" void* __cdecl sub_485B30();
extern "C" void __cdecl sub_699EA0(void*, int);
extern "C" void __cdecl sub_702220(void*, void*);

extern unsigned char byte_E31AA1;

struct GroupSelectionVerb {
    char pad0[4];
    void* field4;
    char pad8[4];
    void* fieldC;
    char pad10[0x10];
    void* field20;
    void method();
};

void GroupSelectionVerb::method()
{
    unsigned char al = byte_E31AA1;
    if (al) {
        sub_5C9FE8((int)al, (const char*)0x00B9CE9C, 0);
    }
    void* esi = field20;
    sub_6F28B0();
    void* ecx = field20;
    if (ecx) {
        esi = (void*)sub_41A3C0();
    } else {
        esi = 0;
    }
    void* ebx = fieldC;
    void* tmp1;
    sub_42B340(esi, &tmp1);
    void* ebp = tmp1;
    void* tmp2;
    sub_42B2E0(esi, &tmp2);
    void* edx = *(void**)tmp2;
    void* ecx2 = *(void**)ebp;
    void* tmp3;
    void* eax = sub_6F9590(ebx, &tmp3, ecx2, edx);
    ebp = *(void**)eax;
    void* ref = tmp3;
    if (ref) {
        void* ebx2 = ref;
        volatile long* cnt = (volatile long*)((char*)ref + 4);
        if (_InterlockedExchangeAdd(cnt, -1) == 1) {
            void** vt = *(void***)ebx2;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(ebx2);
            volatile long* cnt2 = (volatile long*)((char*)ebx2 + 8);
            if (_InterlockedExchangeAdd(cnt2, -1) == 1) {
                void** vt2 = *(void***)ebx2;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(ebx2);
            }
        }
    }
    sub_6FC930(esi, ebp);
    void* ecx3 = field20;
    if (ecx3) {
        void* r = sub_485B30();
        sub_699EA0(r, 8);
    } else {
        sub_699EA0(0, 8);
    }
    void* eax2 = fieldC;
    void* edi = field4;
    edi = (char*)edi + 4;
    if (*(unsigned int*)((char*)edi + 0x18) >= 0x10) {
        edi = *(void**)((char*)edi + 4);
    } else {
        edi = (char*)edi + 4;
    }
    sub_702220(edi, eax2);
    void* ecx4 = tmp3;
    void** vt3 = *(void***)ecx4;
    void (*fn3)() = (void (*)())vt3[0];
    fn3();
}

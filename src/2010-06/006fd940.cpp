// from server: 39% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_41AFE0();
extern "C" void __stdcall sub_4EEEE0();
extern "C" void __stdcall sub_599C50();
extern "C" void __stdcall sub_5CB090();
extern "C" char __stdcall sub_5CB130();
extern "C" void __stdcall sub_7A799A(void*);

struct VBase {
    void* vfptr0;
    void* vfptr1;
    char pad_08[0x18 - 8];
    void* vfptr18;
    void* vfptr1c;
    char pad_20[0x98 - 0x20];
    void* ptr98;
    char pad_9c[0xa0 - 0x9c];
    void* ptrA0;
    char pad_a4[0xa4];
    char field_a4[8];
    char field_ac[8];
    void* ptrB4;
    void* ptrB8;
};

void VBase_dtor(VBase* self) {
    self->vfptr0 = (void*)0xa4b494;
    self->vfptr1 = (void*)0xa4b488;
    self->vfptr18 = (void*)0xa4b47c;
    self->vfptr1c = (void*)0xa4b470;

    char* ebp = self->field_a4;
    if (sub_5CB130()) {
        sub_5CB090();
    }
    char* ebx = self->field_ac;
    if (sub_5CB130()) {
        sub_5CB090();
    }

    void* edi = self->ptrB8;
    if (edi) {
        sub_4EEEE0();
        sub_7A799A(edi);
    }
    edi = self->ptrB4;
    if (edi) {
        sub_4EEEE0();
        sub_7A799A(edi);
    }

    sub_41AFE0();
    sub_41AFE0();

    void* ecx = self->ptrA0;
    if (ecx) {
        volatile long* p = (volatile long*)((char*)ecx + 8);
        if (_InterlockedExchangeAdd(p, -1) == 1) {
            void** vt = *(void***)ecx;
            void (*fn)(void*) = (void (*)(void*))vt[2];
            fn(ecx);
        }
    }

    edi = self->ptr98;
    if (edi) {
        volatile long* p = (volatile long*)((char*)edi + 4);
        if (_InterlockedExchangeAdd(p, -1) == 1) {
            void** vt = *(void***)edi;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(edi);
            volatile long* p2 = (volatile long*)((char*)edi + 8);
            if (_InterlockedExchangeAdd(p2, -1) == 1) {
                void** vt2 = *(void***)edi;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(edi);
            }
        }
    }

    sub_599C50();
}

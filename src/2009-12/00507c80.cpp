// from server: 45% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_98B208(void*);

struct VInstance {
    void* vptr;
    char pad_04[0x14];
    void* field_18;
    char pad_1C[0x04];
    void* field_20;
    char pad_24[0x18];
    void* field_3C;
    char pad_40[0x04];
    void* field_44;
    void dtor();
};

void VInstance::dtor()
{
    this->vptr = (void*)0x9ba81c;

    void* p44 = this->field_44;
    if (p44) {
        volatile long* r44 = (volatile long*)((char*)p44 + 4);
        if (_InterlockedExchangeAdd(r44, -1) == 1) {
            void** vt = *(void***)p44;
            void (*f4)(void*) = (void (*)(void*))vt[1];
            f4(p44);
            volatile long* r44b = (volatile long*)((char*)p44 + 8);
            if (_InterlockedExchangeAdd(r44b, -1) == 1) {
                void** vt2 = *(void***)p44;
                void (*f8)(void*) = (void (*)(void*))vt2[2];
                f8(p44);
            }
        }
    }

    void* p3C = this->field_3C;
    if (p3C) {
        volatile long* r3C = (volatile long*)((char*)p3C + 4);
        if (_InterlockedExchangeAdd(r3C, -1) == 1) {
            void** vt = *(void***)p3C;
            void (*f4)(void*) = (void (*)(void*))vt[1];
            f4(p3C);
            volatile long* r3Cb = (volatile long*)((char*)p3C + 8);
            if (_InterlockedExchangeAdd(r3Cb, -1) == 1) {
                void** vt2 = *(void***)p3C;
                void (*f8)(void*) = (void (*)(void*))vt2[2];
                f8(p3C);
            }
        }
    }

    void* p18 = this->field_18;
    if (p18) {
        void (*fn)(void*, void*, int) = *(void (**)(void*, void*, int))p18;
        if (fn) {
            fn(this->field_20, this->field_20, 2);
        }
        this->field_18 = 0;
    }

    sub_98B208((void*)0xb7a224);
    this->vptr = (void*)0x9a2cc4;
}

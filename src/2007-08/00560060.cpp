// from server: 39% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct FilteredSelection {
    void* vtable0;
    void* vtable4;
    char pad8[8];
    void* vtable10;
    void* vtable14;
    char pad18[0x18];
    void* vtable2c;
    char pad30[0x18];
    void* vtable44;
    char pad48[0x18];
    void* vtable5c;
    char pad60[0x18];
    void* vtable74;
    char pad78[0x14];
    void* vtable8c;
    void* vtablee8;
    void* fieldec;
    void* fieldf0;
    char padf4[4];
    void* fieldf8;
    void* fieldfc;
    void* field100;

    void destructor();
};

extern "C" void __cdecl sub_532550(void*);
extern "C" void __cdecl sub_62fc62(void*);
extern "C" void __cdecl sub_5402b0(void*);

void FilteredSelection::destructor()
{
    this->vtable0 = (void*)0x7a9364;
    this->vtable4 = (void*)0x7a935c;
    this->vtable10 = (void*)0x7a9354;
    this->vtable14 = (void*)0x7a9344;
    this->vtable2c = (void*)0x7a9334;
    this->vtable44 = (void*)0x7a9324;
    this->vtable5c = (void*)0x7a9314;
    this->vtable74 = (void*)0x7a9304;
    this->vtable8c = (void*)0x7a92f4;
    this->vtablee8 = (void*)0x7a92ec;

    if (this->fieldec != 0) {
        sub_532550(&this->vtablee8);
    }

    if (this->fieldf8 != 0) {
        sub_62fc62(this->fieldf8);
    }

    this->fieldf8 = 0;
    this->fieldfc = 0;
    this->field100 = 0;

    void* p = this->fieldf0;
    if (p != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            void** vt = *(void***)p;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(p);
        }
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
            void** vt = *(void***)p;
            void (*fn)(void*) = (void (*)(void*))vt[2];
            fn(p);
        }
    }

    sub_5402b0(this);
}

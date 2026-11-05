// from server: 48% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCountedPtr {
    void* ptr;
    long* refcount;
};

struct Plugin {
    void* field0;
    void* field4;
    char field8[0x18];
    void* field20;
    void* field24;
    void* field28;
    void* field2c;
    void* field30;
    void* field34;
    char field38;

    Plugin(RefCountedPtr* src);
};

extern "C" void* __cdecl operator_new(unsigned int);

void __stdcall sub_4181B0(void*);
void __stdcall sub_4984B0(void);
void __stdcall sub_728830(void);

Plugin::Plugin(RefCountedPtr* src) {
    this->field0 = 0;
    this->field4 = 0;

    void* p = src->ptr;
    long* rc = src->refcount;
    if (rc != 0) {
        _InterlockedExchangeAdd(rc + 1, 1);
    }

    sub_4984B0();

    void* mem = operator_new(0x20);
    if (mem != 0) {
        *(void**)((char*)mem + 4) = 0;
        *(void**)((char*)mem + 8) = 0;
        *(void**)((char*)mem + 0xc) = 0;
        *(void**)((char*)mem + 0x14) = 0;
        *(void**)((char*)mem + 0x18) = 0;
        *(char*)((char*)mem + 0x1c) = 0;
    } else {
        mem = 0;
    }

    sub_4181B0(mem);
    sub_728830();
}

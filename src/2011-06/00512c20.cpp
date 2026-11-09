// from server: 31% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl func_0080a05e();

struct BitStream {
    char pad[0x11];
    void Construct();
    void Reset();
};

void BitStream::Construct() {
    *(int*)((char*)this + 0) = 0;
    *(int*)((char*)this + 4) = 0x800;
    *(int*)((char*)this + 8) = 0;
    *(void**)((char*)this + 0xc) = (char*)this + 0x11;
    *(char*)((char*)this + 0x10) = 1;
}

void BitStream::Reset() {
    *(int*)((char*)this + 0) = 0;
    *(int*)((char*)this + 8) = 0;
}

struct Inner {
    void f090();
    void f110();
    void f610(void*);
    void f660();
    void f880(void*, void*);
};

struct Obj {
    char pad0[0x94];
    Inner inner94;
    char pad1[0xac - 0x94 - sizeof(Inner)];
    Inner innerB8;
    char pad2[0x100];

    void method(int a, int b, int c, int d);
};

struct RefCounted {
    long ref1;
    long ref2;
};

struct Big {
    char pad[0x114];
};

extern void G1_func_004ecf60();
extern void G1_func_004f9e70();
extern void G1_func_006a1db0();

void Obj::method(int a, int b, int c, int d) {
    Inner* pB8 = &this->innerB8;
    pB8->f090();
    int local = 0;
    void* out1;
    void* out2;
    this->inner94.f880(&out1, &out2);
    int edx = *(int*)&out1;
    int edi = *(int*)&out2;
    int* arr = (int*)((char*)this + 0xa8);
    int cnt = *(int*)((char*)this + 0xac);
    int* end = arr + cnt;
    if (edi != *end) {
        pB8->f610(&local);
        RefCounted* rc = (RefCounted*)(edi ? edi - 0xc : 0);
        int ebx = *(int*)((char*)rc + 4);
        RefCounted* r2 = *(RefCounted**)((char*)rc + 8);
        if (r2) {
            _InterlockedExchangeAdd(&r2->ref1, 1);
        }
        unsigned char idx = *(unsigned char*)&d;
        int* slot = (int*)(ebx + idx * 8 + 8);
        if (*slot == 0) {
            Big* big = (Big*)func_0080a05e();
            if (big) {
                BitStream* bs = (BitStream*)big;
                bs->Construct();
            } else {
                big = 0;
            }
            G1_func_004f9e70();
        }
        BitStream* bs = (BitStream*)*slot;
        bs->Reset();
        G1_func_004ecf60();
        G1_func_006a1db0();
        *(int*)(ebx + idx * 4) = 0;
        if (r2) {
            if (_InterlockedExchangeAdd(&r2->ref1, -1) == 1) {
                (*(void(**)(void*))r2)(r2);
                if (_InterlockedExchangeAdd(&r2->ref2, -1) == 1) {
                    (*(void(**)(void*))((char*)r2 + 8))(r2);
                }
            }
        }
        pB8->f660();
        pB8->f110();
    } else {
        pB8->f110();
    }
}

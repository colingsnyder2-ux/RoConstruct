// from server: 26% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl malloc(unsigned int);

struct Inner {
    char pad0[8];
    int f8;
    int fc;
    char pad10[4];
    int f14;
    int f18;
};

struct Outer {
    void* f0;
    void* f4;
};

struct S {
    char pad0[0x10];
    void addRef(void*);
    void* create(Outer*);
};

void* S::create(Outer* arg) {
    Inner* p = (Inner*)malloc(0x20);
    if (p) {
        *(short*)p = 0;
        *(short*)((char*)p + 2) = 1;
    }
    Inner* q = (Inner*)((char*)p + 4);
    if (q) {
        *(int*)((char*)q + 8) = 0xaa7718;
        *(int*)((char*)q + 0xc) = 0;
        *(int*)((char*)q) = 0xaa7bb4;
        *(int*)((char*)q + 8) = 0xaa7bac;
        *(int*)((char*)q + 0x10) = (int)this;
        *(int*)((char*)q + 0x14) = *(int*)arg;
        *(int*)((char*)q + 0x18) = *(int*)((char*)arg + 4);
        *(int*)((char*)q) = 0xaa8198;
        *(int*)((char*)q + 8) = 0xaa8190;
    }
    this->addRef(q);
    return q;
}

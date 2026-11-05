// from server: 5% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Body {
    char pad0[8];
    volatile long refcount;
    char pad1[0x24 - 0xc];
    void* pointList;
    void* pointListEnd;
};

struct Kernel {
    void* upstream;
    void* bodyList;
    void* bodyListEnd;
    Kernel(void* a, void* b);
    Kernel* insertBody(Body* b);
};

Kernel* Kernel::insertBody(Body* b) {
    this->upstream = b;
    void* list = this->bodyList;
    void* listEnd = this->bodyListEnd;
    (void)list;
    (void)listEnd;
    return this;
}

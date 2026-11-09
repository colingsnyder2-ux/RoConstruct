// from server: 87% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct BLD_ControlBlock {
    void* field0;
    volatile long refCount;
};

struct BLD_SharedRef {
    void* field0;
    BLD_ControlBlock* control;
};

struct BLD_BuilderLevelGenFunc {
    void* vtable;
    int field4;
    int field8;
    float fieldC;
    void* field10;
    BLD_ControlBlock* field14;
    void* field18;
    BLD_ControlBlock* field1c;

    BLD_BuilderLevelGenFunc* construct(BLD_SharedRef* p1, BLD_SharedRef* p2, int a, int b, float f);
};

BLD_BuilderLevelGenFunc* BLD_BuilderLevelGenFunc::construct(BLD_SharedRef* p1, BLD_SharedRef* p2, int a, int b, float f) {
    this->vtable = (void*)0x9b3a34;
    this->field4 = a;
    this->field8 = b;
    this->fieldC = f;

    this->field10 = p1->field0;
    BLD_ControlBlock* c1 = p1->control;
    this->field14 = c1;
    if (c1) {
        _InterlockedExchangeAdd(&c1->refCount, 1);
    }

    this->field18 = p2->field0;
    BLD_ControlBlock* c2 = p2->control;
    this->field1c = c2;
    if (c2) {
        _InterlockedExchangeAdd(&c2->refCount, 1);
    }

    return this;
}

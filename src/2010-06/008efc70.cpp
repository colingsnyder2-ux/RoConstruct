// from server: 85% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct SP {
    void* obj;
    long* ref;
};

struct S {
    void* vtbl;
    int field4;
    int field8;
    float fieldC;
    void* field10;
    long* field14;
    void* field18;
    long* field1C;
    S* init(SP* a1, SP* a2, int a3);
};

S* S::init(SP* a1, SP* a2, int a3) {
    this->field4 = a3;
    this->vtbl = (void*)0xa8a1e0;
    this->field8 = 0;
    this->fieldC = 0.0f;

    this->field10 = a1->obj;
    this->field14 = a1->ref;
    if (this->field14 != 0) {
        _InterlockedExchangeAdd((volatile long*)(this->field14 + 1), 1);
    }

    this->field18 = a2->obj;
    this->field1C = a2->ref;
    if (this->field1C != 0) {
        _InterlockedExchangeAdd((volatile long*)(this->field1C + 1), 1);
    }

    return this;
}

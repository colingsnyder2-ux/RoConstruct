// from server: 94% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S {
    char pad0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    S* assign(S* other);
};

S* S::assign(S* other) {
    pad0 = other->pad0;
    field4 = other->field4;
    field8 = other->field8;
    fieldC = other->fieldC;
    field10 = other->field10;
    field14 = other->field14;
    if (field14 != 0) {
        _InterlockedExchangeAdd((volatile long*)(field14 + 4), 1);
    }
    return this;
}

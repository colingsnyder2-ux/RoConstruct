// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
struct Counted { void* vt; long use; long weak; };
struct S {
    char pad0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    Counted* field14;
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
        _InterlockedIncrement(&field14->use);
    }
    return this;
}

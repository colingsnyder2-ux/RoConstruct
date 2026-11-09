// from server: 92% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct MechanismItem {
    void* ptr0;
    void* refcount1;
    int field8;
    int fieldC;
    double field10;
    int field18;
    void* refcount1c;
};

struct DirectPhysicsReceiver {
    MechanismItem tempItem;
    DirectPhysicsReceiver& operator=(const MechanismItem& other);
};

DirectPhysicsReceiver& DirectPhysicsReceiver::operator=(const MechanismItem& other) {
    tempItem.ptr0 = other.ptr0;
    tempItem.refcount1 = other.refcount1;
    if (tempItem.refcount1) {
        _InterlockedExchangeAdd((volatile long*)((char*)tempItem.refcount1 + 4), 1);
    }
    tempItem.field8 = other.field8;
    tempItem.fieldC = other.fieldC;
    tempItem.field10 = other.field10;
    tempItem.field18 = other.field18;
    tempItem.refcount1c = other.refcount1c;
    if (tempItem.refcount1c) {
        _InterlockedExchangeAdd((volatile long*)((char*)tempItem.refcount1c + 4), 1);
    }
    return *this;
}

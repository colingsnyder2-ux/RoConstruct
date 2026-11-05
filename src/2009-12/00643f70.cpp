// from server: 62% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VVector2Holder {
    void __cdecl assign(const VVector2Holder* other);
};

void VVector2Holder::assign(const VVector2Holder* other) {
    int* src = *(int**)other;
    int* dst;
    if (src != 0) {
        dst = src + 7;
    } else {
        dst = 0;
    }
    int* self = *(int**)this;
    self[0] = (int)dst;
    int* ref = (int*)((char*)other + 4);
    int count = ref[0];
    self[1] = count;
    if (count != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)count + 4), 1);
    }
}

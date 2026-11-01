// from server: 68% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VPlayersListener {
    char pad[0x130];
    int m_refCounted;
    long* m_refCount;
    void getRefCounted(int* out);
};

void VPlayersListener::getRefCounted(int* out) {
    volatile long local = 0;
    out[0] = m_refCounted;
    long* rc = m_refCount;
    out[1] = (int)rc;
    if (rc) {
        _InterlockedExchangeAdd(rc + 1, 1);
    }
    (void)local;
}

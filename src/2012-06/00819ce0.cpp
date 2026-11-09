// from server: 13% by Intel
struct ChatService {
    int refcount;
    int unused1;
    int unused2;
    int release();
};

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long* ptr, long value);
#pragma intrinsic(_InterlockedAdd)

int ChatService::release() {
    int old = _InterlockedExchangeAdd((volatile long*)&refcount, -1);
    if (old == 1) {
        return 0;
    }
    return 1;
}

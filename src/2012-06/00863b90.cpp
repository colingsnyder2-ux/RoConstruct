// from server: 61% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

typedef void (__stdcall *CloseHandleFn)(void*);

struct RefCounted {
    int refCount;
};

void __cdecl operator_delete(void*);

void stream_buffer_assign_range(RefCounted** first, RefCounted** last, RefCounted** dest) {
    if (first == last) {
        return;
    }

    CloseHandleFn closeHandle = reinterpret_cast<CloseHandleFn>(0x00B221E8);

    do {
        RefCounted* srcObj = *first;
        if (srcObj) {
            _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&srcObj->refCount), 1);
        }

        RefCounted* oldDest = *dest;
        *dest = srcObj;

        if (oldDest) {
            long oldCount = _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&oldDest->refCount), -1);
            if (oldCount == 1) {
                int vtablePtr = *reinterpret_cast<int*>(oldDest);
                if (vtablePtr && vtablePtr != -1) {
                    reinterpret_cast<void(__stdcall*)(int)>(vtablePtr)(vtablePtr);
                }
                int secondPtr = *reinterpret_cast<int*>(reinterpret_cast<char*>(oldDest) + 4);
                if (secondPtr && secondPtr != -1) {
                    reinterpret_cast<void(__stdcall*)(int)>(secondPtr)(secondPtr);
                }
                operator_delete(oldDest);
            }
        }

        ++first;
        ++dest;
    } while (first != last);
}

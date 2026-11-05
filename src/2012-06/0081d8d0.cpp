// from server: 45% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refCount;
};

struct Tuple {
    RefCounted** begin;
    RefCounted** end;
};

void __stdcall Tuple_AssignRange(Tuple* thisPtr, int index, int count, RefCounted** src) {
    RefCounted** begin = thisPtr->begin;
    RefCounted** end = thisPtr->end;
    int size = static_cast<int>(end - begin);
    RefCounted** dest = begin + index;
    RefCounted** destEnd = begin + size;

    if (dest < destEnd) {
        do {
            RefCounted* newObj = src[index];
            *dest = newObj;

            RefCounted* oldObj = dest[1];
            if (oldObj != newObj) {
                if (newObj) {
                    long* newRef = &newObj->refCount;
                    _InterlockedExchangeAdd(newRef, 1);
                }

                if (oldObj) {
                    long* oldRef = &oldObj->refCount;
                    long prev = _InterlockedExchangeAdd(oldRef, -1);
                    if (prev == 1) {
                        void (__thiscall* dtor)(RefCounted*) = *reinterpret_cast<void (__thiscall**)(RefCounted*)>(oldObj->vptr);
                        dtor(oldObj);
                        long* weakRef = reinterpret_cast<long*>(reinterpret_cast<char*>(oldObj) + 8);
                        long prevWeak = _InterlockedExchangeAdd(weakRef, -1);
                        if (prevWeak == 1) {
                            void (__thiscall* deleteFn)(RefCounted*) = *reinterpret_cast<void (__thiscall**)(RefCounted*)>(reinterpret_cast<char*>(oldObj->vptr) + 8);
                            deleteFn(oldObj);
                        }
                    }
                }
            }

            dest += 2;
            ++index;
        } while (dest < destEnd);
    }

    int remaining = size - index;
    if (remaining > 0) {
        extern void __stdcall Tuple_DestroyRange(Tuple*, int, int);
        Tuple_DestroyRange(thisPtr, index, remaining);
    }
}

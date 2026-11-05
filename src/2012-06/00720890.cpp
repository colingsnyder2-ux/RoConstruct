// from server: 30% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    int vptr;
    long refCount;
    virtual void Release() = 0;
    virtual void DeleteThis() = 0;
};

struct Item {
    int vptr;
    RefCounted* ptr1;
    int field8;
    RefCounted* ptr2;
    int field10;
};

Item* __cdecl CopyItems(Item* first, Item* last, Item* dest) {
    if (first == last) {
        return dest;
    }

    Item* currentSrc = first;
    Item* currentDest = dest;

    while (true) {
        currentDest->vptr = currentSrc->vptr;

        RefCounted* newPtr1 = currentSrc->ptr1;
        RefCounted* oldPtr1 = currentDest->ptr1;
        if (newPtr1 != oldPtr1) {
            if (newPtr1) {
                _InterlockedExchangeAdd(&newPtr1->refCount, 1);
            }
            if (oldPtr1) {
                if (_InterlockedExchangeAdd(&oldPtr1->refCount, -1) == 1) {
                    oldPtr1->Release();
                    if (_InterlockedExchangeAdd(&oldPtr1->refCount, -1) == 1) {
                        oldPtr1->DeleteThis();
                    }
                }
            }
            currentDest->ptr1 = newPtr1;
        }

        currentDest->field8 = currentSrc->field8;

        RefCounted* newPtr2 = currentSrc->ptr2;
        RefCounted* oldPtr2 = currentDest->ptr2;
        if (newPtr2 != oldPtr2) {
            if (newPtr2) {
                _InterlockedExchangeAdd(&newPtr2->refCount, 1);
            }
            if (oldPtr2) {
                if (_InterlockedExchangeAdd(&oldPtr2->refCount, -1) == 1) {
                    oldPtr2->Release();
                    if (_InterlockedExchangeAdd(&oldPtr2->refCount, -1) == 1) {
                        oldPtr2->DeleteThis();
                    }
                }
            }
            currentDest->ptr2 = newPtr2;
        }

        currentDest->field10 = currentSrc->field10;

        currentSrc = reinterpret_cast<Item*>(reinterpret_cast<char*>(currentSrc) + 20);
        currentDest = reinterpret_cast<Item*>(reinterpret_cast<char*>(currentDest) + 20);

        if (currentSrc == last) {
            break;
        }
    }

    return currentDest;
}

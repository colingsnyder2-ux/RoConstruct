// from server: 40% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    long refCount;
};

struct Item {
    RefCounted* ptr;
    int unk1;
    int unk2;
    int unk3;
    int unk4;
};

void __cdecl func_008525e0(Item* dest, Item* src, Item* end)
{
    Item* currentSrc = src;
    Item* currentDest = dest;

    while (currentSrc != end) {
        if (currentDest != 0) {
            RefCounted* obj = currentSrc->ptr;
            currentDest->ptr = obj;
            if (obj != 0) {
                _InterlockedExchangeAdd(&obj->refCount, 1);
            }
            currentDest->unk1 = currentSrc->unk1;
            currentDest->unk2 = currentSrc->unk2;
            currentDest->unk3 = currentSrc->unk3;
            currentDest->unk4 = currentSrc->unk4;
        }
        currentSrc++;
        currentDest++;
    }
}

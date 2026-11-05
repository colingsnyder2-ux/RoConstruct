// from server: 42% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ChangePropertyItem {
    void* vtable;      // 0x0
    int field4;        // 0x4
    int field8;        // 0x8
    int fieldC;        // 0xC
    void __cdecl invoke(int, int);
};

void ChangePropertyItem::invoke(int a, int b) {
    int local4 = field4;
    int local8 = field8;
    if (local8 != 0) {
        _InterlockedExchangeAdd((volatile long*)(local8 + 8), 1);
    }
    void (*fn)(void*, int*, int) = *(void (**)(void*, int*, int))vtable;
    int args[2];
    args[0] = local4;
    args[1] = local8;
    fn(this, args, fieldC);
}

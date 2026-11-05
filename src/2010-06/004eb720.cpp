// from server: 48% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ChangePropertyItem {
    void* vtable;
    int field4;
    int field8;
    int fieldC;
    void invoke(int a, int b);
};

void ChangePropertyItem::invoke(int a, int b)
{
    int local0 = field4;
    int local4 = field8;
    if (local4 != 0) {
        _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(local4 + 8), 1);
    }
    void (*fn)(int, int, int*, int) = reinterpret_cast<void (*)(int, int, int*, int)>(vtable);
    fn(a, fieldC, &local0, b);
}

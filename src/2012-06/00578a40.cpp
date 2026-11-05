// from server: 26% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Slot {
    void* field_0;
    void* field_4;
    void* field_8;
    void* field_C;
    void* field_10;
    void* field_14;
    void* field_18;

    void operator()(void* a1, void* a2);
};

void Slot::operator()(void* a1, void* a2) {
    void* v10 = field_10;
    void* v14 = field_14;
    void* v18 = field_18;

    if (v14) {
        _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(static_cast<char*>(v14) + 8), 1);
    }

    void (*func)(void*, void*, void*) = reinterpret_cast<void (*)(void*, void*, void*)>(field_C);
    func(v10, a1, a2);
}

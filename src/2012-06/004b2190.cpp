// from server: 68% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern char string_literal[];
extern "C" void __cdecl sub_4b20f0(void* ptr, const char* str);

struct Outer {
    char _vpad[4];
    void* innerPtr;
    void release();
};

void Outer::release() {
    void* arg1 = reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 4);
    void* inner = *reinterpret_cast<void**>(arg1);
    volatile long* refCountPtr = reinterpret_cast<volatile long*>(reinterpret_cast<char*>(inner) + 0x1c);
    if (_InterlockedExchangeAdd(refCountPtr, -1) != 0) {
        return;
    }
    sub_4b20f0(arg1, static_cast<const char*>(string_literal));
}

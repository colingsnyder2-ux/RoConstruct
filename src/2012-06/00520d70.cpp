// from server: 68% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall string_copy_ctor(void*, const void*);

struct VPlayer {
    void* field0;
    char pad1[0x1c];
    void* field20;
    void* field24;
    void* field28;
    void construct(void* a, void* src);
};

void VPlayer::construct(void* a, void* src) {
    field0 = a;
    string_copy_ctor((char*)this + 4, (char*)src + 4);
    field20 = *(void**)((char*)src + 0x20);
    if (field20) {
        _InterlockedExchangeAdd((volatile long*)((char*)field20 + 8), 1);
    }
    field24 = *(void**)((char*)src + 0x24);
    field28 = *(void**)((char*)src + 0x28);
    if (field28) {
        _InterlockedExchangeAdd((volatile long*)((char*)field28 + 8), 1);
    }
}

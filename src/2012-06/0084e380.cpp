// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_55f050(void*);

struct LuaArguments {
    void* field_0x0;
    void* field_0x4;
    void __cdecl assign(void* other);
};

void LuaArguments::assign(void* other) {
    void* tmp = sub_55f050(other);
    field_0x0 = *(void**)tmp;
    field_0x4 = *(void**)((char*)tmp + 4);
    if (field_0x4) {
        _InterlockedExchangeAdd((volatile long*)((char*)field_0x4 + 4), 1);
    }
}

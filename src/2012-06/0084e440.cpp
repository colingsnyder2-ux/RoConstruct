// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_84e050(void*);

struct LuaArguments {
    void* field_0x0;
    void* field_0x4;
    void __cdecl assign(void* src);
};

void LuaArguments::assign(void* src) {
    void* tmp = 0;
    void* result = sub_84e050(src);
    void** p = (void**)result;
    field_0x0 = p[0];
    field_0x4 = p[1];
    if (field_0x4) {
        _InterlockedExchangeAdd((volatile long*)((char*)field_0x4 + 4), 1);
    }
}

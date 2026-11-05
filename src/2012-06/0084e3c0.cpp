// from server: 55% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_75beb0(void*);

struct LuaArguments {
    void* field_0x0;
    void* field_0x4;
    void __cdecl f(void*);
};

void LuaArguments::f(void* arg) {
    void* result = sub_75beb0(arg);
    void* v = *(void**)result;
    *(void**)arg = v;
    void* r = *(void**)((char*)result + 4);
    *(void**)((char*)arg + 4) = r;
    if (r != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)r + 4), 1);
    }
}

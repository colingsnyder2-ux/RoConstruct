// from server: 23% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct LuaArguments {
    void* vfptr;
    int unk0;
    int unk1;
    int unk2;
    int unk3;
    int refcount;
};

int func_0084ca60(void* this_ptr, void* dst, void* src)
{
    if (!dst)
        return 0;
    *(char*)dst = *(char*)src;
    *(int*)((char*)dst + 4) = *(int*)((char*)src + 4);
    *(int*)((char*)dst + 8) = *(int*)((char*)src + 8);
    *(int*)((char*)dst + 0xc) = *(int*)((char*)src + 0xc);
    *(int*)((char*)dst + 0x10) = *(int*)((char*)src + 0x10);
    *(void**)((char*)dst + 0x14) = *(void**)((char*)src + 0x14);
    if (*(void**)((char*)dst + 0x14)) {
        return _InterlockedExchangeAdd((volatile long*)((char*)dst + 0x14 + 4), 1) == 1;
    }
    return 1;
}

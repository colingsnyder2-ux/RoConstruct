// from server: 42% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub1 {
    char pad[0x1cc0];
    void sub_54e500();
};

struct Sub2 {
    char pad[0x94];
    void sub_544470();
};

struct Replicator {
    char pad0[0x94];
    Sub2 sub2;
    char pad1[0x1cbc - 0x94 - sizeof(Sub2)];
    void* ptr_1cbc;
    Sub1 sub1;
    void sub_637b00();
    void func_54e570();
};

void Replicator::func_54e570()
{
    sub1.sub_54e500();
    void* p = ptr_1cbc;
    if (p) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            (*(void (__thiscall**)(void*))(*(char**)p + 4))(p);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                (*(void (__thiscall**)(void*))(*(char**)p + 8))(p);
            }
        }
    }
    sub2.sub_544470();
    sub_637b00();
}

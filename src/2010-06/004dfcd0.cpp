// from server: 36% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct PacketJob {
    char pad0[0x1d0];
    void* field_1d0;
    char pad1[0x1f8 - 0x1d0 - 4];
    void* field_1f8;
    void dtor();
};

extern "C" void __cdecl sub_7a799a(void*);
extern "C" void __cdecl sub_462820(void*);
extern "C" void __cdecl sub_79c630(void*);

void PacketJob::dtor()
{
    void* p = this->field_1f8;
    if (p) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
            (*(void (__thiscall**)(void*))(*(char**)p + 8))(p);
        }
    }
    sub_462820(&this->field_1d0);
    sub_7a799a(this->field_1d0);
    sub_79c630(this);
}

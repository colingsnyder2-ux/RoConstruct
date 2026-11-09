// from server: 50% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct SharedPtr {
    void* px;
    long* pn;
};

struct MarshaledListener {
    char pad0[4];
    char pad1[0x14];
    void* field18;
    void* method(void* a, void* b, void* c, void* d, void* e);
};

struct Selection {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void* field18;
};

extern "C" void* __cdecl sub_62fef6(unsigned int size);
extern "C" void __cdecl sub_464ec0(void* a, void* b);
extern "C" void __cdecl sub_433140(void* a, void* b);
extern "C" void __cdecl sub_41da00(void* a);
extern "C" void* __cdecl sub_4622d0(void* a, void* b, void* c);

void* MarshaledListener::method(void* a, void* b, void* c, void* d, void* e)
{
    void* result = sub_62fef6(0x20);
    void* esi;
    if (result) {
        SharedPtr* sp = (SharedPtr*)result;
        sp->px = a;
        sp->pn = (long*)b;
        if (b) {
            _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
        }
        sp[1].px = c;
        sp[1].pn = (long*)d;
        if (d) {
            _InterlockedExchangeAdd((volatile long*)((char*)d + 4), 1);
        }
        esi = sub_4622d0(result, this, e);
    } else {
        esi = 0;
    }
    void* local = esi;
    sub_464ec0((char*)this + 4, &local);
    sub_433140(this->field18, esi);
    sub_41da00(&local);
    return esi;
}

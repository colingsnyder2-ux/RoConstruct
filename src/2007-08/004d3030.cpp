// from server: 32% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub {
    void* vptr;
    long refCount;
    long weakCount;
};

struct Chunk {
    void* vptr;
    char pad[0xcc];
    Sub* sub_d0;
    char pad2[0x10];
    Sub sub_d4;
    Sub sub_e8;

    void destroy();
};

void __fastcall sub_7285a0(Sub* s);

void Chunk::destroy()
{
    this->vptr = (void*)0x79f1ac;
    sub_7285a0(&this->sub_e8);
    sub_7285a0(&this->sub_d4);

    Sub* p = this->sub_d0;
    if (p) {
        if (_InterlockedExchangeAdd(&p->refCount, -1) == 1) {
            ((void (__thiscall*)(Sub*))p->vptr)(p);
            if (_InterlockedExchangeAdd(&p->weakCount, -1) == 1) {
                ((void (__thiscall*)(Sub*))((void**)p->vptr)[2])(p);
            }
        }
    }
}

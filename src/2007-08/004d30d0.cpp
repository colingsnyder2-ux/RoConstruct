// from server: 41% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub {
    void destroy();
    void release();
};

struct Chunk {
    void* vptr;
    char pad[0xcc];
    Sub* ref;
    char pad2[0x10];
    Sub sub1;
    char pad3[0x10];
    Sub sub2;
    void dtor();
};

void __stdcall sub_7285a0(Sub* s);

void Chunk::dtor()
{
    this->vptr = (void*)0x79f1d8;
    sub_7285a0(&this->sub2);
    sub_7285a0(&this->sub1);
    Sub* r = this->ref;
    if (r) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)r + 4), -1) == 1) {
            void** vt = *(void***)r;
            ((void (__thiscall*)(Sub*))vt[1])(r);
        }
        if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
            void** vt = *(void***)r;
            ((void (__thiscall*)(Sub*))vt[2])(r);
        }
    }
    ((void (__thiscall*)(Chunk*))0x4d2ee0)(this);
}

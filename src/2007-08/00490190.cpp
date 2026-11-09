// from server: 43% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Inner {
    char pad[0x20];
};

struct Player {
    void* field0;
    void* field4;
    char pad8[0x18];
    void* field20;
    void* field24;
    void* field28;
    void* field2c;
    void* field30;
    void* field34;
    char field38;
};

extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" void __cdecl sub_4181B0(Player*, void*);
extern "C" void __cdecl sub_48FEA0(void*, void*);
extern "C" void __cdecl sub_728830(Player*);

void Player_ctor(Player* self, void* arg);

void Player_ctor(Player* self, void* arg)
{
    self->field0 = 0;
    self->field4 = 0;

    void** src = (void**)arg;
    void* a = src[0];
    void* b = src[1];

    void* local[2];
    local[0] = a;
    local[1] = b;
    if (b != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
    }

    sub_48FEA0((char*)self + 8, local);

    void* p = sub_62FEF6(0x20);
    if (p != 0) {
        *(void**)((char*)p + 4) = 0;
        *(void**)((char*)p + 8) = 0;
        *(void**)((char*)p + 0xc) = 0;
        *(void**)((char*)p + 0x14) = 0;
        *(void**)((char*)p + 0x18) = 0;
        *(char*)((char*)p + 0x1c) = 0;
    } else {
        p = 0;
    }

    sub_4181B0(self, p);
    sub_728830(self);
}

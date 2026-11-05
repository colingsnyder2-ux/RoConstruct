// from server: 45% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    long refs;
    void addRef() {
        _InterlockedExchangeAdd(&refs, 1);
    }
};

struct SharedPtr {
    void* px;
    RefCounted* pi;
    SharedPtr() : px(0), pi(0) {}
    SharedPtr(const SharedPtr& o) : px(o.px), pi(o.pi) {
        if (pi) pi->addRef();
    }
};

struct Player {
    SharedPtr sp;
    char pad[8];
    void* field;
    Player(const SharedPtr& p);
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

void sub_48FDF0(void*);
void sub_4181B0(void*, void*);
void sub_728830(void*);

Player::Player(const SharedPtr& p) {
    sp.px = 0;
    sp.pi = 0;
    sp = p;
    sub_48FDF0(&pad[0]);
    void* mem = operator_new(0x20);
    if (mem) {
        *(void**)((char*)mem + 4) = 0;
        *(void**)((char*)mem + 8) = 0;
        *(void**)((char*)mem + 0xc) = 0;
        *(void**)((char*)mem + 0x14) = 0;
        *(void**)((char*)mem + 0x18) = 0;
        *(char*)((char*)mem + 0x1c) = 0;
    }
    sub_4181B0(this, mem);
    sub_728830(this);
}

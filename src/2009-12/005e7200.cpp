// from server: 49% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" void __stdcall SetEvent(void*);

extern "C" void __cdecl sub_401630();
extern "C" void* __cdecl sub_4109E0();
extern "C" void __cdecl sub_418890();
extern "C" void __cdecl sub_5E69B0();
extern "C" void* __cdecl sub_5E7160();

struct RefCounted {
    char pad0[0x18];
    void* field18;
    char pad1[0x04];
    long refcount;
};

struct Holder {
    char pad0[0x20];
    long refcount;
    char pad1[0x04];
    long flags;
};

void sub_5E7200()
{
    sub_401630();
    Holder* h = (Holder*)sub_5E7160();
    volatile long* rc = (volatile long*)&h->refcount;
    sub_418890();
    RefCounted* r = (RefCounted*)h;
    void* p = *(void**)((char*)r->field18 + 4);
    sub_5E69B0();
    *(void**)((char*)r->field18 + 4) = r->field18;
    r->refcount = 0;
    *(void**)r->field18 = r->field18;
    *(void**)((char*)r->field18 + 8) = r->field18;
    if (_InterlockedExchangeAdd(rc, -1) == 1) {
        long old = _InterlockedExchangeAdd((volatile long*)&h->flags, 0x80000000);
        if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
            if (!_interlockedbittestandset((volatile long*)&h->flags, 0x1e)) {
                void* e = sub_4109E0();
                SetEvent(e);
            }
        }
    }
}

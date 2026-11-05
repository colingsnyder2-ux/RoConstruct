// from server: 51% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    int a;
    int b;
};

struct Obj {
    void* vtbl;
    long ref1;
    long ref2;
};

struct S {
    char pad0[0xa0];
    Inner* begin;
    char pad1[4];
    Inner* end;
    char pad2[0x100];
    int f();
};

extern "C" int __cdecl sub_542910();
extern "C" void __cdecl sub_53bd90(void*);
extern "C" void* __cdecl sub_401630(void*, void*, void*);
extern "C" int __cdecl sub_537fd0();
extern "C" void __cdecl sub_4020a0(void*, void*);
extern "C" void __cdecl sub_636d80(void*, void*);
extern "C" void __cdecl sub_98b760();

int S::f()
{
    if (sub_542910() != 0)
        return 0;

    Inner local;
    sub_53bd90(&local);

    void* ebx = *(void**)((char*)&local + 4);

    sub_401630((void*)0xb805f0, (void*)0x5391f0, 0);
    int idx = sub_537fd0();

    int count = (int)((this->end - this->begin) >> 3);
    if ((unsigned)idx >= (unsigned)count)
        sub_98b760();

    Inner* slot = this->begin + idx;
    slot->a = local.a;
    sub_4020a0(&slot->b, (char*)&local + 4);

    sub_636d80(ebx, this);

    Obj* o = *(Obj**)((char*)&local + 4);
    if (o != 0) {
        if (_InterlockedExchangeAdd(&o->ref1, -1) == 1) {
            void (*fn)(Obj*) = *(void(**)(Obj*))((char*)*(void**)o + 4);
            fn(o);
        }
        if (_InterlockedExchangeAdd(&o->ref2, -1) == 1) {
            void (*fn)(Obj*) = *(void(**)(Obj*))((char*)*(void**)o + 8);
            fn(o);
        }
    }

    return (int)ebx;
}

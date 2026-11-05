// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" void __stdcall SetEvent(void*);

struct Inner {
    char pad0[0x1e0];
    char pad1[8];
};

struct Obj {
    char pad0[0x10];
    Inner* inner;
};

struct Ref {
    void* ptr;
    char flag;
};

struct Big {
    char data[0x140];
};

extern "C" void __stdcall sub_4edf60(void*);
extern "C" void __stdcall sub_411500(void*);
extern "C" void __stdcall sub_4ee520(void*, void*, void*);
extern "C" void* __stdcall sub_40a2b0();

extern double g_a66280;

struct StatsUpdateJob {
    void run(int a, int b);
};

void StatsUpdateJob::run(int a, int b)
{
    Big big;
    Ref ref;
    char buf[0x140];
    double d1, d2, d3, d4, d5, d6;

    d1 = g_a66280;
    d2 = 0.0;
    d3 = 0.0;
    d4 = 0.0;
    d5 = 0.0;
    d6 = 0.0;

    ref.flag = 1;
    ref.ptr = 0;

    sub_4edf60(&big);

    Obj* o = (Obj*)this;
    Inner* in = o->inner;
    ref.ptr = (char*)in + 0x1e0;
    ref.flag = 0;
    sub_411500(&ref);

    Inner* in2 = ((Obj*)this)->inner;
    sub_4ee520((char*)in2 + 0x1e8, &ref, &big);

    if (ref.flag) {
        long old = _InterlockedExchangeAdd((volatile long*)ref.ptr, (long)0x80000000);
        if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
            void* p = ref.ptr;
            if (!_interlockedbittestandset((volatile long*)p, 0x1e)) {
                void* e = sub_40a2b0();
                SetEvent(e);
            }
        }
    }
}

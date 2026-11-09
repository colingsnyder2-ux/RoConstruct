// from server: 26% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" void __stdcall SetEvent(void*);

struct RefCounted {
    long refcount;
};

struct Holder {
    char pad[0x10];
    RefCounted* ptr;
};

extern "C" void* __cdecl sub_4B3E10();
extern "C" void __cdecl sub_411500(void*);
extern "C" void __cdecl sub_475C20(Holder*, void*);
extern "C" void* __cdecl sub_40A2B0();

void __fastcall func(Holder* self)
{
    if (self->ptr != 0) {
        void* a = sub_4B3E10();
        void* local4 = a;
        char local8 = 0;
        sub_411500(&local4);
        RefCounted* p = self->ptr;
        if (p != 0) {
            self->ptr = 0;
            sub_475C20(self, p);
        }
        if (local8 != 0) {
            RefCounted* q = (RefCounted*)local4;
            long old = _InterlockedExchangeAdd(&q->refcount, (long)0x80000000);
            if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
                if (!_interlockedbittestandset((volatile long*)&q->refcount, 0x1e)) {
                    void* h = sub_40A2B0();
                    SetEvent(h);
                }
            }
        }
    }
}

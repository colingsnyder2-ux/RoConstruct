// from server: 40% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct SignalDesc {
    int field0;
    int field4;
};

struct VReplicator {
    char pad[0x134];
    SignalDesc* begin;
    SignalDesc* end;

    int addSignalDesc(int a2, int a3);
};

struct Item {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

extern "C" int __cdecl sub_4949A0();
extern "C" void __cdecl sub_48C4A0(void*);
extern "C" void __cdecl sub_725520(void*, void*, void*);
extern "C" int __cdecl sub_4918C0();
extern "C" void __cdecl sub_402A60(void*, void*);
extern "C" void __cdecl sub_541630(void*, void*);

int VReplicator::addSignalDesc(int a2, int a3)
{
    int result;
    SignalDesc* slot;
    int idx;
    Item* item;
    int old;

    result = sub_4949A0();
    if (result != 0)
        return result;

    sub_48C4A0(&a2);

    sub_725520((void*)0x8bdfa8, (void*)0x492120, 0);

    idx = sub_4918C0();

    if (this->begin != 0 || (unsigned)idx >= (unsigned)((this->end - this->begin) >> 3))
        _invalid_parameter_noinfo();

    slot = this->begin + idx;
    slot->field0 = a2;
    sub_402A60(&slot->field4, &a3);

    sub_541630((void*)a3, this);

    item = (Item*)a3;
    if (item != 0) {
        old = _InterlockedExchangeAdd(&item->refCount, -1);
        if (old == 1) {
            void** vt = (void**)item->vptr;
            ((void (__thiscall*)(Item*))vt[1])(item);
            old = _InterlockedExchangeAdd(&item->weakCount, -1);
            if (old == 1) {
                vt = (void**)item->vptr;
                ((void (__thiscall*)(Item*))vt[2])(item);
            }
        }
    }

    return a2;
}

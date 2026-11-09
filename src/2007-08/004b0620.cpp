// from server: 29% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall invalid_parameter_noinfo();

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct SignalDesc {
    int f();
};

struct Replicator {
    char pad[0x134];
    void* vecBegin;
    void* vecEnd;
};

struct Item {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

extern "C" int __cdecl sub_4AFAC0();
extern "C" void __cdecl sub_4A8ED0(void*);
extern "C" void __cdecl sub_4A74D0();
extern "C" void* __cdecl sub_4A5C40();
extern "C" void __cdecl sub_402A60(void*, void*);
extern "C" void __cdecl sub_541630(void*, void*);
extern "C" void* __cdecl sub_725520(void*, void*, void*);
extern "C" void __cdecl sub_77E6D8();

int SignalDesc::f()
{
    Replicator* self = (Replicator*)this;
    int result;
    void* local10;
    void* local14;
    void* local18;
    Item* item;
    unsigned int idx;
    unsigned int count;

    result = sub_4AFAC0();
    if (result != 0)
        return result;

    sub_4A8ED0(&local10);
    item = (Item*)local10;

    sub_725520((void*)0x8be97c, (void*)0x4a74d0, 0);
    sub_4A74D0();
    idx = (unsigned int)sub_4A5C40();

    if (self->vecBegin != 0) {
        count = ((char*)self->vecEnd - (char*)self->vecBegin) >> 3;
        if (idx < count)
            goto have_slot;
    }
    sub_77E6D8();

have_slot:
    {
        char* slot = (char*)self->vecBegin + idx * 8;
        *(void**)slot = local10;
        sub_402A60(slot + 4, &local14);
    }

    sub_541630(item, self);

    if (local14 != 0) {
        RefCounted* rc = (RefCounted*)local14;
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void (__stdcall *dtor)(void*) = *(void (__stdcall**)(void*))((char*)rc->vptr + 4);
            dtor(rc);
            if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                void (__stdcall *dtor2)(void*) = *(void (__stdcall**)(void*))((char*)rc->vptr + 8);
                dtor2(rc);
            }
        }
    }

    return (int)item;
}

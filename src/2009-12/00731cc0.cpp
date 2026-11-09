// from server: 34% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_74D590(int);

struct RefCounted {
    void** vptr;
    long refcount;
    long weakref;
};

struct EventDesc {
    int field0;
    int field4;
    int field8;
    int fieldC;
};

struct Slot {
    int field0;
    char pad[4];
    EventDesc desc;
    int f();
};

int Slot::f()
{
    int a = *(int*)((char*)this + 0x18);
    int b = *(int*)((char*)this + 0x1C);
    int c = *(int*)((char*)this + 0x20);
    int d = *(int*)((char*)this + 0x24);
    EventDesc tmp;
    tmp.field0 = a;
    tmp.field4 = b;
    tmp.field8 = c;
    tmp.fieldC = d;
    RefCounted* p = (RefCounted*)d;
    if (p) {
        _InterlockedExchangeAdd(&p->refcount, 1);
    }
    int r = sub_74D590(0xb51754);
    int v = r ? 0xb51754 : 0;
    this->field0 = v;
    if (p) {
        if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))p->vptr[1])(p);
            if (_InterlockedExchangeAdd(&p->weakref, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))p->vptr[2])(p);
            }
        }
    }
    return 0;
}

// from server: 45% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    volatile long ref4;
    volatile long ref8;
};

struct ClearBackpack {
    void* vptr;
    char pad0[0x0C];
    RefCounted* field10;
    char pad1[0x08];
    RefCounted* field1c;
    void Clear();
};

void sub_5e6c00(ClearBackpack*);

void ClearBackpack::Clear()
{
    this->vptr = (void*)0x00a2e24c;
    RefCounted* p = this->field1c;
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref4, -1) == 1) {
            p->slot4();
            if (_InterlockedExchangeAdd(&p->ref8, -1) == 1) {
                p->slot8();
            }
        }
    }
    RefCounted* q = this->field10;
    if (q) {
        if (_InterlockedExchangeAdd(&q->ref4, -1) == 1) {
            q->slot4();
            if (_InterlockedExchangeAdd(&q->ref8, -1) == 1) {
                q->slot8();
            }
        }
    }
    sub_5e6c00(this);
}

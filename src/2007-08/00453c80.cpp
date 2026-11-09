// from server: 37% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    volatile long refCount;
    volatile long weakRefCount;
};

struct CNameItem {
    char pad[0x7c];
    RefCounted* ptr;
    void destructor();
};

void __stdcall helper6538a0();

void CNameItem::destructor()
{
    helper6538a0();
    RefCounted* p = (this != 0) ? this->ptr : 0;
    if (p != 0) {
        if (_InterlockedExchangeAdd(&p->refCount, -1) == 1) {
            p->unknown1();
            if (_InterlockedExchangeAdd(&p->weakRefCount, -1) == 1) {
                p->unknown2();
            }
        }
    }
}

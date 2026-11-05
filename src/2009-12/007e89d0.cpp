// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);

struct VCEvent {
    char pad0[0x2c];
    char cs[0x18];
    char pad44[0x18];
    void (__stdcall *vtbl)(void*);
    void* ptr;
    void release();
};

struct RefCounted {
    void** vtbl;
    volatile long refcount;
    volatile long weakref;
};

void __stdcall sub_7ea500(void* out, void* src);

void VCEvent::release()
{
    EnterCriticalSection(cs);
    sub_7ea500(&ptr, (char*)this + 0x44);
    LeaveCriticalSection(cs);
    void* p = ptr;
    void** vt = *(void***)p;
    void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vt[2];
    fn(this);
    RefCounted* rc = (RefCounted*)ptr;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            void** v = *(void***)rc;
            void (__stdcall *d)(void*) = (void (__stdcall *)(void*))v[1];
            d(rc);
            if (_InterlockedExchangeAdd(&rc->weakref, -1) == 1) {
                void** v2 = *(void***)rc;
                void (__stdcall *d2)(void*) = (void (__stdcall *)(void*))v2[2];
                d2(rc);
            }
        }
    }
}

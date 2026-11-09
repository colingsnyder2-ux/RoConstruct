// from server: 26% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall LeaveCriticalSection(void*);

struct EventInstance {
    void* descriptor;
    void* source;
};

struct BridgeBase {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual void invoke(EventInstance* instance);
};

struct EventBridge : BridgeBase {
    void invoke(EventInstance* instance);
};

struct LockGuard {
    void* cs;
    char locked;
    LockGuard(void* cs_);
    ~LockGuard();
};

void EventBridge::invoke(EventInstance* instance)
{
    LockGuard guard(*(void**)((char*)this + 0x18));
    EventInstance local;
    local.descriptor = instance->descriptor;
    local.source = instance->source;
    if (local.source) {
        _InterlockedExchangeAdd((volatile long*)((char*)local.source + 4), 1);
    }
    local.descriptor = instance->descriptor;
    local.source = instance->source;
    if (local.source) {
        _InterlockedExchangeAdd((volatile long*)((char*)local.source + 4), 1);
    }
    BridgeBase::invoke(&local);
}

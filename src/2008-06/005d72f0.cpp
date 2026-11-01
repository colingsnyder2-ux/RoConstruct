// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct ControlBlock {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct SharedMember {
    void* object;
    ControlBlock* control;
    ~SharedMember();
};

inline SharedMember::~SharedMember()
{
    ControlBlock* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct ListMember {
    unsigned char storage[24];
    ~ListMember();
};

struct Base {
    unsigned char storage[0x134];
    ~Base();
};

struct TimerService : Base {
    SharedMember shared;
    ListMember timers;
    ~TimerService();
};

TimerService::~TimerService()
{
}

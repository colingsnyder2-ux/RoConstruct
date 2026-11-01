// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct EventData;

struct Listener
{
    void detach(EventData*);
};

struct RefCount
{
    virtual ~RefCount();
    virtual void dispose() = 0;
    virtual void destroy() = 0;

    volatile long strong;
    volatile long weak;
};

struct SharedData
{
    void* object;
    RefCount* control;
};

struct EventBase
{
    virtual ~EventBase();
};

struct EventData : EventBase
{
    SharedData data;
    Listener* listener;

    virtual ~EventData();
};

__forceinline EventBase::~EventBase()
{
}

EventData::~EventData()
{
    if (listener)
        listener->detach(this);

    RefCount* p = data.control;
    if (p)
    {
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

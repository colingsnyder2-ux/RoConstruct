// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Logger
{
    void __cdecl writeLog(int, const char*);
};

struct Shared
{
    Logger* object;
    Control* control;

    Logger* operator->() const;
    ~Shared();
};

__forceinline Logger* Shared::operator->() const
{
    return object;
}

__forceinline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Message
{
    virtual void unused();
    virtual const char* text();
};

extern Shared __cdecl getLogger();

void __cdecl func_00428850(Message* message)
{
    getLogger()->writeLog(3, message->text());
}

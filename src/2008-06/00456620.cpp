// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;

    void release();
    void releaseWeak();
};

inline void Control::releaseWeak()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        releaseWeak();
    }
}

struct Ptr
{
    void* object;
    Control* control;

    Ptr(const Ptr&);
    ~Ptr();
};

inline Ptr::Ptr(const Ptr& other)
    : object(other.object), control(other.control)
{
    if (control)
    {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Ptr::~Ptr()
{
    if (control)
        control->release();
}

struct Holder
{
    void* object;
    Control* control;

    Holder(Ptr);
    ~Holder();
};

struct RecordItem
{
    virtual void reserved();
    char data[120];

    RecordItem();
    ~RecordItem();
};

struct S : Holder, RecordItem
{
    int index;

    S(int, Ptr);
    virtual void reserved();
};

S::S(int value, Ptr pointer)
    : Holder(pointer), RecordItem(), index(value)
{
}

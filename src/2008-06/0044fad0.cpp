// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long use_count;
    volatile long weak_count;

    void release();
    void weak_release();
};

inline void Control::weak_release()
{
    if (_InterlockedDecrement(&weak_count) == 0)
        destroy();
}

inline void Control::release()
{
    if (_InterlockedDecrement(&use_count) == 0)
    {
        dispose();
        weak_release();
    }
}

struct Property
{
    virtual void set(bool value);
};

struct Object
{
    char padding[0x1f0];
    Property property;
};

struct Handle
{
    Object* object;
    Control* control;
    ~Handle();
};

inline Handle::~Handle()
{
    if (control)
        control->release();
}

struct Source
{
    Handle get();
};

struct CRobloxDoc
{
    char padding0[0x48];
    int state;
    char padding1[0x48];
    Source* source;

    void func_0044fad0(int value);
};

void CRobloxDoc::func_0044fad0(int value)
{
    state = value;
    if (source)
        source->get().object->property.set(value == 1);
}

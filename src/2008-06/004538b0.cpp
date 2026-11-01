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

struct Service
{
    void perform();
};

struct Object
{
    Service *getService();
};

struct Shared
{
    Object *object;
    Control *control;

    Shared(const Shared &);
    ~Shared();
};

inline Shared::Shared(const Shared &other)
    : object(other.object), control(other.control)
{
    if (control)
    {
        volatile long *count = &control->use_count;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Context
{
    Shared getObject();
};

struct Guard
{
    char storage[12];

    Guard(Shared);
    ~Guard();
};

struct CRobloxDoc
{
    char padding[0x94];
    Context *context;

    void func_004538b0();
};

void CRobloxDoc::func_004538b0()
{
    Shared object = context->getObject();
    Guard guard(object);
    object.object->getService()->perform();
}

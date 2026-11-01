// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();

    long use_count;
    long weak_count;

    void add_ref();
    void release();
};

inline void Control::add_ref()
{
    _InterlockedIncrement(&use_count);
}

inline void Control::release()
{
    if (_InterlockedDecrement(&use_count) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak_count) == 0)
            destroy();
    }
}

template<class T> struct Shared
{
    T* pointer;
    Control* control;

    Shared(const Shared&);
    template<class U> Shared(const Shared<U>&);
    ~Shared();
};

template<class T>
inline Shared<T>::Shared(const Shared<T>& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        control->add_ref();
}

template<class T>
template<class U>
inline Shared<T>::Shared(const Shared<U>& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        control->add_ref();
}

template<class T>
inline Shared<T>::~Shared()
{
    if (control)
        control->release();
}

struct Model;

struct Source
{
    Shared<Model> get();
};

struct Guard
{
    unsigned char storage[12];

    Guard(Shared<void>);
    ~Guard();
};

struct Signal
{
    void fire(int);
};

struct Object
{
    Signal* getSignal();
};

struct CRobloxDoc
{
    unsigned char padding[0x94];
    Source* source;

    Shared<Object> getObject();
    void func_00455460();
};

inline Signal* signalFrom(const Shared<Object>& value)
{
    return value.pointer ? value.pointer->getSignal() : 0;
}

void CRobloxDoc::func_00455460()
{
    Guard guard(source->get());
    signalFrom(getObject())->fire(2);
}

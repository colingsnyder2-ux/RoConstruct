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
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

template<class T>
struct Shared
{
    T* object;
    Control* control;
    ~Shared();
    T* get() const;
};

template<class T>
inline Shared<T>::~Shared()
{
    if (control)
        control->release();
}

template<class T>
inline T* Shared<T>::get() const
{
    return object;
}

struct Mutex
{
    void* handle;
    bool criticalSection;
    unsigned int count;
    void sub_563090();
    void sub_5630e0();
};

struct Lock
{
    Mutex* mutex;
    bool locked;
    Lock(Mutex&);
    ~Lock();
};

inline Lock::Lock(Mutex& m) : mutex(&m)
{
    mutex->sub_563090();
    locked = true;
}

inline Lock::~Lock()
{
    if (locked)
        mutex->sub_5630e0();
}

struct Object;

struct Holder
{
    void sub_55a8f0(Object*);
};

extern Mutex globalMutex;
extern Object* globalObject;

Shared<Holder> __cdecl sub_408ed0();
Shared<Object> __cdecl sub_5690f0();

Object* __cdecl sub_412d50()
{
    Lock lock(globalMutex);
    if (globalObject == 0)
    {
        Shared<Holder> holder = sub_408ed0();
        holder.object->sub_55a8f0(sub_5690f0().get());
    }
    return globalObject;
}

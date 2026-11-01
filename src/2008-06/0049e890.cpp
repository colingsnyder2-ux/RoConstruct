// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Mutex {
    void* handle;
    bool criticalSection;
    unsigned int count;
    void lock();
    void unlock();
};

extern Mutex globalMutex;
extern void* globalInstance;

struct Guard {
    Mutex* mutex;
    bool locked;
    explicit Guard(Mutex*);
    ~Guard();
};

inline Guard::Guard(Mutex* p) : mutex(p)
{
    mutex->lock();
    locked = true;
}

inline Guard::~Guard()
{
    if (locked)
        mutex->unlock();
}

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct Object {
    void initialize(Object*);
};

struct Shared {
    Object* object;
    Control* control;
    ~Shared();
    Object* get() const;
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

inline Shared::~Shared()
{
    if (control)
        control->release();
}

inline Object* Shared::get() const
{
    return object;
}

Shared __cdecl makeFirst();
Shared __cdecl makeSecond();

void* __cdecl getInstance()
{
    Guard guard(&globalMutex);
    if (!globalInstance) {
        Shared first = makeFirst();
        first.object->initialize(makeSecond().get());
    }
    return globalInstance;
}

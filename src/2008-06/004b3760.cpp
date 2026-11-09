// from server: 100% by king_originala
struct Key {
    unsigned int first;
    unsigned int second;
};

struct Mutex {
    void *handle;
    bool criticalSection;
    unsigned int count;

    void lock();
    void unlock();
};

struct Registry {
    unsigned char reserved[32];
    Mutex mutex;

    void remove(const Key &key);
};

extern Registry *registry;
extern int initializationFlag;
extern void initializeRegistry();
extern void __cdecl initializeOnce(void (__cdecl *function)(), int *flag);

struct Lock {
    Mutex *mutex;
    bool locked;

    Lock(Mutex &value);
    ~Lock();
};

inline Lock::Lock(Mutex &value) : mutex(&value), locked(false)
{
    mutex->lock();
    locked = true;
}

inline Lock::~Lock()
{
    if (locked)
        mutex->unlock();
}

struct S {
    unsigned int reserved;
    bool active;
    unsigned int first;
    unsigned int second;

    void f();
};

void S::f()
{
    if (active) {
        Key key;
        key.first = first;
        key.second = second;
        initializeOnce(initializeRegistry, &initializationFlag);
        Registry *value = registry;
        Lock lock(value->mutex);
        value->remove(key);
    }
    active = false;
}

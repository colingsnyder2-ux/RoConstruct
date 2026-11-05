// from server: 100% by king_originala
struct Mutex {
    void *handle;
    bool criticalSection;
    unsigned int count;

    void lock();
    void unlock();
};

struct ScopedLock {
    Mutex &mutex;
    bool locked;

    ScopedLock(Mutex &m);
    ~ScopedLock();
};

inline ScopedLock::ScopedLock(Mutex &m) : mutex(m), locked(false)
{
    mutex.lock();
    locked = true;
}

inline ScopedLock::~ScopedLock()
{
    if (locked)
        mutex.unlock();
}

struct Container {
    void insert(void **value);
};

struct CSelectionTreeCtrl {
    unsigned char padding0[0xc4];
    Mutex mutex;
    unsigned char padding1[0x34];
    Container container;

    void f(void *value);
};

void CSelectionTreeCtrl::f(void *value)
{
    ScopedLock lock(mutex);
    container.insert(&value);
}

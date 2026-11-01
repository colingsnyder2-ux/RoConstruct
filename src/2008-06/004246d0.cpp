// from server: 100% by king_originala
struct Mutex {
    void *handle;
    bool criticalSection;
    unsigned int count;

    void lock();
    void unlock();
};

struct Result {
    void *data[3];
};

struct Container {
    void operation(Result *result, const unsigned int *value);
};

struct LockGuard {
    Mutex *mutex;
    bool locked;

    LockGuard(Mutex &m) : mutex(&m) {
        mutex->lock();
        locked = true;
    }

    ~LockGuard() {
        if (locked)
            mutex->unlock();
    }
};

struct CSelectionTreeCtrl {
    char padding0[0xc4];
    Mutex mutex;
    char padding1[0x34];
    Container container;

    void f(unsigned int value);
};

void CSelectionTreeCtrl::f(unsigned int value)
{
    LockGuard guard(mutex);
    Result result;
    container.operation(&result, &value);
}

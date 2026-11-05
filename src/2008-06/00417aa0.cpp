// from server: 100% by king_originala
struct Mutex {
    void *handle;
    bool criticalSection;
    unsigned int count;
    void lock();
    void unlock();
};

struct Result {
    void finish();
};

struct Callable {
    Result *invoke(int, int, int, int, int, int);
};

struct LockGuard {
    Mutex *mutex;
    bool locked;

    LockGuard(Mutex &m) : mutex(&m), locked(false) {
        mutex->lock();
        locked = true;
    }

    ~LockGuard() {
        if (locked)
            mutex->unlock();
    }
};

struct S {
    char padding[0x130];
    Mutex mutex;
    Callable *callable;
    void f(int a, int b);
};

void S::f(int a, int b)
{
    LockGuard guard(mutex);
    if (callable)
        callable->invoke(0, 0, 0, a, b, 6)->finish();
}

// from server: 100% by king_originala
struct Mutex {
    void *handle;
    bool criticalSection;
    unsigned int count;

    void lock();
    void unlock();
};

struct Guard {
    Mutex *mutex;
    bool locked;

    Guard(Mutex &m);
    ~Guard();
};

inline Guard::Guard(Mutex &m) : mutex(&m), locked(false)
{
    mutex->lock();
    locked = true;
}

inline Guard::~Guard()
{
    if (locked)
        mutex->unlock();
}

struct Item {
    void first();
    void second();
};

struct Owner {
    Item *get(int index);
};

struct S {
    unsigned char padding[0x130];
    Mutex mutex;
    Owner *owner;

    void f();
};

void S::f()
{
    Guard guard(mutex);
    if (owner) {
        owner->get(0)->first();
        owner->get(5)->second();
    }
}

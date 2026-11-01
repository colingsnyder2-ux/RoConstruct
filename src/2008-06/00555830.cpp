// from server: 100% by king_originala
struct Mutex {
    void* handle;
    char kind;
    void acquire();
    void release();
};

struct Container {
    void update(const unsigned int* value);
};

struct Guard {
    Mutex* mutex;
    bool locked;
    Guard(Mutex& value);
    ~Guard();
};

inline Guard::Guard(Mutex& value) : mutex(&value), locked(false)
{
    mutex->acquire();
    locked = true;
}

inline Guard::~Guard()
{
    if (locked)
        mutex->release();
}

struct S {
    char padding[0x280];
    Mutex mutex;
    Container container;
    void prepare(unsigned int value);
    void f(unsigned int value);
};

void S::f(unsigned int value)
{
    Guard guard(mutex);
    prepare(value);
    container.update(&value);
}

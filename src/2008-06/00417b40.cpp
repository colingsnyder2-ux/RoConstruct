// from server: 100% by king_originala
struct Value {
    unsigned char padding[24];
    void *context;
    int reserved;
    int value;

    Value &assign(const Value &other);
    ~Value();
};

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

struct Destination {
    unsigned char padding[0x14];
    Value value;
};

struct Owner {
    unsigned char padding[0xfc];
    Destination *destination;
};

struct S {
    unsigned char padding[0x130];
    Mutex mutex;
    Owner *owner;

    void f(Value value);
};

void S::f(Value value)
{
    Guard guard(mutex);
    Owner *p = owner;
    if (p)
        p->destination->value.assign(value);
}

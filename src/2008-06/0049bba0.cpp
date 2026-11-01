// from server: 100% by king_originala
struct Mutex {
    void lock();
    void unlock();
};

struct Key {
    unsigned int first;
    unsigned int second;
};

struct Descriptor;

struct Registry {
    unsigned char padding[32];
    Mutex mutex;
    Descriptor **find(const Key &key);
};

extern Registry *registry;
extern int initializationState;
extern void __cdecl initializeRegistry();
extern void __cdecl initializeOnce(void (__cdecl *)(), int *);

struct LockGuard {
    Mutex *mutex;
    bool locked;

    LockGuard(Mutex *m);
    ~LockGuard();
};

__forceinline LockGuard::LockGuard(Mutex *m) : mutex(m) {
    mutex->lock();
    locked = true;
}

__forceinline LockGuard::~LockGuard() {
    if (locked)
        mutex->unlock();
}

struct Descriptor {
    void *vtable;
    bool registered;
    Key key;

    void registerDescriptor();
};

void Descriptor::registerDescriptor() {
    if (!registered) {
        Key localKey = key;
        initializeOnce(initializeRegistry, &initializationState);
        Registry *r = registry;
        LockGuard guard(&r->mutex);
        *r->find(localKey) = this;
    }
    registered = true;
}

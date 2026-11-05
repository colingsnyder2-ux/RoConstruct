// from server: 100% by king_originala
struct Mutex {
    void* handle;
    char kind;
    void lock();
    void unlock();
};

struct Guard {
    Mutex* mutex;
    bool locked;
    Guard(Mutex& m);
    ~Guard();
};

inline Guard::Guard(Mutex& m) : mutex(&m), locked(false) {
    mutex->lock();
    locked = true;
}

inline Guard::~Guard() {
    if (locked)
        mutex->unlock();
}

struct Map {
    bool& lookup(const int& key);
};

struct S {
    char padding[0x280];
    Mutex mutex;
    Map map;
    void f(int key);
};

void S::f(int key) {
    Guard guard(mutex);
    map.lookup(key) = true;
}

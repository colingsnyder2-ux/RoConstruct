// from server: 100% by king_originala
struct Result {
    unsigned char data[28];
    ~Result();
};

struct Item {
    unsigned char padding[20];
    Result value;
};

struct LockData {
    void* first;
    void* second;
    int third;

    LockData();
    void acquire(void*);
    ~LockData();
};

__forceinline LockData::LockData()
    : first(0), second(0) {
}

struct Lock {
    LockData data;

    Lock(void*);
    ~Lock();
};

__forceinline Lock::Lock(void* mutex)
    : data() {
    data.third = 0;
    data.acquire(mutex);
}

__forceinline Lock::~Lock() {
}

struct Source {
    unsigned char padding[0x198];
    void* mutex;
};

struct Interface {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual Result fetch(Result*) = 0;
};

struct S {
    unsigned char padding[0x128];
    Source* source;
    Interface* target;

    Result f(Item*);
};

Result S::f(Item* item) {
    Lock lock(source->mutex);
    return target->fetch(item ? &item->value : 0);
}

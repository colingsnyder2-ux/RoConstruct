// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Control {
    virtual void first() = 0;
    virtual void second() = 0;
    virtual void dispose() = 0;
    long other;
    volatile long references;

    void addRef();
    void release();
};

inline void Control::addRef() {
    _InterlockedIncrement(&references);
}

inline void Control::release() {
    if (_InterlockedDecrement(&references) == 0)
        dispose();
}

struct Count {
    Control* control;

    Count(const Count& value);
    ~Count();
};

inline Count::Count(const Count& value) : control(value.control) {
    if (control)
        control->addRef();
}

inline Count::~Count() {
    if (control)
        control->release();
}

struct Shared {
    void* object;
    Count count;

    Shared(const Shared& value);
    ~Shared();
};

inline Shared::Shared(const Shared& value)
    : object(value.object), count(value.count) {
}

inline Shared::~Shared() {
}

struct Iterator {
    void* owner;
    unsigned int offset;
    Shared& get();
};

extern void __cdecl removeObject(Shared value);

struct S {
    unsigned char padding[0x130];
    void* owner;
    unsigned char unused[12];
    Shared** map;
    unsigned int mapSize;
    unsigned int offset;
    int size;
    int limit;

    void f();
};

void S::f() {
    while (size > limit) {
        unsigned int front = offset;
        if (front > front + size)
            _invalid_parameter_noinfo();

        Iterator iterator;
        iterator.owner = owner;
        iterator.offset = front;
        removeObject(iterator.get());

        if (size) {
            Shared* value = &map[offset >> 1][offset & 1];
            value->~Shared();

            ++offset;
            if (mapSize * 2 <= offset)
                offset = 0;
            if (--size == 0)
                offset = 0;
        }
    }
}

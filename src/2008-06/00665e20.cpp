// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Count {
    virtual ~Count();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count;
    long weak_count;
};

struct Event {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void fire(void*, int);
};

struct Object {
    char padding[0x1cc];
    Event event;
};

struct Shared {
    Object* pointer;
    Count* count;
    ~Shared();
    Object* operator->() const;
};

struct Weak {
    Object* pointer;
    Count* count;
    ~Weak();
    Shared lock() const;
};

struct Owner {
    bool ready();
    Weak get() const;
};

struct Tool {
    char padding[0x1c];
    Owner* owner;
    void run(void*);
};

inline Shared::~Shared()
{
    if (count) {
        Count* p = count;
        if (_InterlockedDecrement(&p->use_count) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak_count) == 0)
                p->destroy();
        }
    }
}

inline Object* Shared::operator->() const
{
    return pointer;
}

inline Weak::~Weak()
{
    if (count) {
        Count* p = count;
        if (_InterlockedDecrement(&p->weak_count) == 0)
            p->destroy();
    }
}

void Tool::run(void* argument)
{
    if (owner->ready())
        owner->get().lock()->event.fire(argument, 0);
}

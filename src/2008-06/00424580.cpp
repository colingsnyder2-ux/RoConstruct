// from server: 100% by king_originala
struct Lock {
    void acquire();
    void f();
};

struct Guard {
    Lock* lock;
    bool held;
    Guard(Lock* p);
    ~Guard();
};

__forceinline Guard::Guard(Lock* p) : lock(p)
{
    lock->acquire();
    held = true;
}

__forceinline Guard::~Guard()
{
    if (held)
        lock->f();
}

struct Result {
    unsigned int data[3];
};

struct Container {
    Result insert(unsigned int value);
};

struct Selection;

struct ParentVtbl {
    char padding[0x15c];
    void (__thiscall *notify)(void*, Selection*);
};

struct Parent {
    ParentVtbl* vtbl;
    char padding[0xc0];
    Lock lock;
};

struct Selection {
    char padding[0x58];
    Parent* parent;
    unsigned int reserved;
    Container container;
    void f(unsigned int value);
};

void Selection::f(unsigned int value)
{
    {
        Guard guard(&parent->lock);
        container.insert(value);
    }
    parent->vtbl->notify(parent, this);
}

// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

void __cdecl operator delete(void*);

struct ContentProvider {
    int value;
    unsigned char flag;
    int count;
    void f();
};

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

struct Guard {
    ContentProvider* provider;
    unsigned char active;
    ~Guard();
};

struct DataModel {
    Shared shared;
    Guard* guard;
    ~DataModel();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

inline Guard::~Guard()
{
    if (active) {
        provider->f();
        active = 0;
    }
}

DataModel::~DataModel()
{
    delete guard;
}

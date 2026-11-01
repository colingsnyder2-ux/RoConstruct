// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Base
{
    virtual ~Base();
    char storage[0x374];
};

struct Base2
{
    virtual ~Base2();
    char storage[0x20];
};

struct Base3
{
    virtual ~Base3();
    char storage[0x20];
};

struct CInstanceExplorer : Base, Base2, Base3
{
    Shared shared;
    virtual ~CInstanceExplorer();
    void reset(int);
};

CInstanceExplorer::~CInstanceExplorer()
{
    reset(0);
}

// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* pointer;
    Control* control;
    ~Shared();
};

struct Member {
    unsigned char storage[4];
    void cleanup();
};

struct S;

struct Owner {
    void remove(S*);
};

struct Base {
    virtual ~Base();
};

struct S : Base {
    Shared shared;
    Owner* owner;
    Member member;
    virtual ~S();
};

inline Base::~Base()
{
}

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

S::~S()
{
    if (owner)
        owner->remove(this);
    member.cleanup();
}

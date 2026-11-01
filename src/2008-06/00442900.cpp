// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Object {
    void* get();
};

struct Shared {
    Object* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Guard {
    char storage[12];
    Guard(Object*);
    ~Guard();
};

struct Grid {
    void set(void*);
};

struct CDataModelPropGrid {
    void f(Shared, Shared);
};

void CDataModelPropGrid::f(Shared value, Shared other)
{
    Object*& current =
        *reinterpret_cast<Object**>(reinterpret_cast<char*>(this) - 0xac);

    if (current) {
        Guard guard(current);
        reinterpret_cast<Grid*>(reinterpret_cast<char*>(this) - 0x244)->set(0);
    }

    current = value.object;
    if (current) {
        Guard guard(current);
        reinterpret_cast<Grid*>(reinterpret_cast<char*>(this) - 0x244)->set(
            current ? current->get() : 0);
    }
}

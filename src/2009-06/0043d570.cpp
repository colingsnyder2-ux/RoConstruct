// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
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
    Shared(const Shared& r) : object(r.object), control(r.control) {
        if (control) _InterlockedIncrement(&control->strong);
    }
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
    void* storage;
    Guard(Object*, int);
    ~Guard();
};

struct Grid {
    void set(void*);
    void setObject(Shared);
    void clear();
};

struct CDataModelPropGrid {
    void f(Shared, Shared);
};

void CDataModelPropGrid::f(Shared value, Shared other)
{
    Object*& current =
        *reinterpret_cast<Object**>(reinterpret_cast<char*>(this) - 0xd8);

    if (current) {
        Guard guard(current, 1);
        reinterpret_cast<Grid*>(reinterpret_cast<char*>(this) - 0x278)->clear();
        reinterpret_cast<Grid*>(reinterpret_cast<char*>(this) - 0x278)->set(0);
    }

    current = value.object;
    if (current) {
        Guard guard(current, 1);
        reinterpret_cast<Grid*>(reinterpret_cast<char*>(this) - 0x278)->setObject(value);
        reinterpret_cast<Grid*>(reinterpret_cast<char*>(this) - 0x278)->set(
            current ? current->get() : 0);
    }
}

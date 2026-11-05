// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


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

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedIncrement(count);
    }
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

Shared __cdecl convert(const Shared&);

struct Item {
    char storage[0xb0];

    static void* __stdcall operator new(unsigned int);
    static void __stdcall operator delete(void*);
    Item(Shared, Shared);
};

struct Records {
    void update();
};

struct Owner {
    Records* insert(Item*);
};

struct S {
    char padding[0x48];
    Shared member;

    void f(unsigned int, Shared);
};

void S::f(unsigned int, Shared argument)
{
    Shared value = convert(argument);
    if (value.object) {
        Item* item = new Item(value, member);
        reinterpret_cast<Owner*>(reinterpret_cast<char*>(this) - 0x54)
            ->insert(item)->update();
    }
}

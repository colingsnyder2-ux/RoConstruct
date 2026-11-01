// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace RBX {
struct Instance;
struct ServiceProvider;
}

RBX::ServiceProvider* __cdecl func_00580800(RBX::Instance*);

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Handle {
    Control* control;
    ~Handle();
    Handle& operator=(const Handle&);
};

__forceinline Handle::~Handle()
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

struct Product {
    void* object;
    Handle handle;
    Product(const Product&);
    Product& operator=(const Product&);
};

__forceinline Product& Product::operator=(const Product& other)
{
    object = other.object;
    handle = other.handle;
    return *this;
}

Product __cdecl func_00618a40(RBX::ServiceProvider*);

struct S {
    RBX::Instance* instance;
    Product cached;
    void* get(void*);
};

void* S::get(void*)
{
    if (!cached.object)
        cached = func_00618a40(func_00580800(instance));
    return cached.object;
}

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace RBX {
struct Instance;
struct ServiceProvider;
}

RBX::ServiceProvider* __cdecl func_00492e00(RBX::Instance*);

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();

    volatile long strongCount;
    volatile long weakCount;
};

struct Reference {
    Control* control;

    Reference& operator=(const Reference&);
    ~Reference();
};

inline Reference::~Reference()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strongCount) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weakCount) == 0)
                p->destroy();
        }
    }
}

struct Product {
    void* object;
    Reference reference;

    Product& operator=(const Product&);
};

inline Product& Product::operator=(const Product& other)
{
    object = other.object;
    reference = other.reference;
    return *this;
}

Product __cdecl func_00618a40(RBX::ServiceProvider*);

struct S {
    RBX::Instance* instance;
    Product cached;

    void* get(int);
};

void* S::get(int)
{
    if (!cached.object)
        cached = func_00618a40(func_00492e00(instance));
    return cached.object;
}

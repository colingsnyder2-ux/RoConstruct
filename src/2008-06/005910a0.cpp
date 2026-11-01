// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String;
typedef void (__thiscall *StringDestructor)(String*);
extern StringDestructor stringDestructor;

struct String {
    unsigned char storage[28];
    ~String();
};

inline String::~String()
{
    stringDestructor(this);
}

typedef String (__cdecl *StringConcat)(const String&, const char*);
extern StringConcat stringConcat;

struct Name {
    const String* value;
    Name();
    const String& text() const;
};

struct Instance {
    unsigned char storage[0x400];
    unsigned char disabled;
    Name name() const;
};

struct ServiceProvider {
    bool contains(const String*);
};

extern ServiceProvider* __cdecl func_00590dd0(Instance*);

struct Product {
    virtual void unused();
    virtual void setName(const String&);
    void attach(ServiceProvider*);
    void configure(const String*);
};

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared;
extern void __cdecl createProduct(Shared*);

struct Shared {
    Product* object;
    Control* control;
    Shared();
    ~Shared();
};

inline Shared::Shared()
{
    createProduct(this);
}

__forceinline Shared::~Shared()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct RootInstance {
    void process(Instance*);
};

void RootInstance::process(Instance* instance)
{
    if (!instance->disabled) {
        ServiceProvider* provider =
            func_00590dd0(reinterpret_cast<Instance*>(this));
        if (!provider->contains(instance->name().value)) {
            Shared product;
            product.object->attach(provider);
            Product* current = product.object;
            current->configure(instance->name().value);
            current = product.object;
            current->setName(
                stringConcat(instance->name().text(), " Team"));
        }
    }
}

// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String;
extern String* (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];
    __forceinline String(const char*);
    __forceinline ~String();
};

__forceinline String::String(const char* text)
{
    stringConstruct(this, text);
}

__forceinline String::~String()
{
    stringDestroy(this);
}

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Count {
    Control* control;
    Count& operator=(const Count&);
    __forceinline ~Count();
};

__forceinline Count::~Count()
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

struct Shared {
    void* pointer;
    Count count;
    __forceinline ~Shared();
};

__forceinline Shared::~Shared()
{
}

Shared __cdecl makeShared(void*);

struct Parent {
    char* find(const String&);
};

struct S {
    char padding0[0x104];
    Parent* parent;
    char padding1[0xe4];
    Shared cached;
    void* f();
};

void* S::f()
{
    if (!cached.pointer && parent) {
        String name("Head");
        char* object = parent->find(name);
        cached = makeShared(object ? object + 0xe4 : 0);
    }
    return cached.pointer;
}

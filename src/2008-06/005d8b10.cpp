// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String;

extern void (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    unsigned char storage[28];
    String(const char*);
    ~String();
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
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Reference {
    Control* control;
    Reference& operator=(const Reference&);
};

struct Pair {
    void* pointer;
    Reference reference;

    Pair& operator=(const Pair&);
    ~Pair();
};

__forceinline Pair& Pair::operator=(const Pair& other)
{
    pointer = other.pointer;
    reference = other.reference;
    return *this;
}

__forceinline Pair::~Pair()
{
    if (reference.control) {
        Control* p = reference.control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Parent {
    void* find(const String&);
};

Pair __cdecl makePair(void*);

struct S {
    unsigned char padding0[0x104];
    Parent* parent;
    unsigned char padding1[0xec];
    Pair cached;

    void* get();
};

void* S::get()
{
    if (!cached.pointer && parent) {
        String name("Torso");
        void* found = parent->find(name);
        cached = makePair(found ? static_cast<unsigned char*>(found) + 0xe4 : 0);
    }
    return cached.pointer;
}

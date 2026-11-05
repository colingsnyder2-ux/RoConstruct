// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String;
extern String* (__thiscall* string_copy)(String*, const String&);
extern void (__thiscall* string_destroy)(String*);

struct String
{
    char storage[28];
    String(const String&);
    ~String();
};

inline String::String(const String& other)
{
    string_copy(this, other);
}

inline String::~String()
{
    string_destroy(this);
}

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* pointer;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

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

struct S
{
    String string;
    Shared shared;
    S(String, Shared);
};

S::S(String value, Shared owner)
    : string(value), shared(owner)
{
}

// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct Shared
{
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct String;

typedef const char* (__thiscall *StringCStr)(const String*);
typedef void (__thiscall *StringDestroy)(String*);

extern StringCStr string_c_str;
extern StringDestroy string_destroy;

struct String
{
    unsigned char data[28];
    const char* c_str() const;
    ~String();
};

inline const char* String::c_str() const
{
    return string_c_str(this);
}

inline String::~String()
{
    string_destroy(this);
}

struct Lock
{
    int value;
    unsigned char flag;
    int count;
    void enter();
    void leave();
};

struct Guard
{
    Lock* lock;
    bool acquired;
    Guard(Lock& value);
    ~Guard();
};

inline Guard::Guard(Lock& value) : lock(&value), acquired(false)
{
    lock->enter();
    acquired = true;
}

inline Guard::~Guard()
{
    if (acquired)
        lock->leave();
}

struct Function
{
    void invoke(Shared value, int kind, const char* text);
};

struct Object
{
    unsigned char padding[0x130];
    Lock lock;
    Function* function;
    void f(Shared value, int kind, String text);
};

void Object::f(Shared value, int kind, String text)
{
    Guard guard(lock);
    if (function)
        function->invoke(value, kind, text.c_str());
}

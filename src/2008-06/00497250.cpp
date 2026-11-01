// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

__forceinline void Control::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared {
    void* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control) {
    if (control)
        _InterlockedIncrement(&control->strong);
}

__forceinline Shared::~Shared() {
    if (control)
        control->release();
}

struct String;
extern String* (__thiscall* string_copy)(String*, const String*);
extern void (__thiscall* string_destroy)(String*);

struct String {
    unsigned long storage[7];
    String(const String&);
    ~String();
};

__forceinline String::String(const String& other) {
    string_copy(this, &other);
}

__forceinline String::~String() {
    string_destroy(this);
}

struct Base {
    unsigned long storage[2];
    Base(Shared value);
    ~Base();
};

struct S : Base {
    String name;
    S(Shared value, String text);
};

S::S(Shared value, String text)
    : Base(value), name(text) {
}

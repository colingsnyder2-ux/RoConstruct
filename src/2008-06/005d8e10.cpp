// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String;
extern void (__thiscall *string_construct)(String*, const char*);
extern void (__thiscall *string_destroy)(String*);

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

inline String::String(const char* text) {
    string_construct(this, text);
}

inline String::~String() {
    string_destroy(this);
}

struct Control {
    virtual void reserved() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Handle {
    Control* control;
    Handle& operator=(const Handle&);
    ~Handle();
};

__forceinline Handle::~Handle() {
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
    void* object;
    Handle handle;
    ~Shared();
};

__forceinline Shared::~Shared() {
}

struct Instance {
    void* find(const String&);
};

extern Shared __cdecl acquire(void*);

struct S {
    char padding0[0x104];
    Instance* parent;
    char padding1[0x10c];
    void* cached;
    Handle owner;
    void assign(const Shared&);
    void* f();
};

__forceinline void S::assign(const Shared& value) {
    cached = value.object;
    owner = value.handle;
}

void* S::f() {
    if (!cached && parent) {
        String name("Left Arm");
        void* found = parent->find(name);
        assign(acquire(found ? static_cast<char*>(found) + 0xe4 : 0));
    }
    return cached;
}

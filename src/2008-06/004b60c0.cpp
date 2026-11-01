// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Control {
    virtual void reserved() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Text;
extern void (__thiscall *textConstruct)(Text*, const char*);
extern void (__thiscall *textDestroy)(Text*);

struct Text {
    unsigned char storage[28];
    Text(const char*);
    ~Text();
};

inline Text::Text(const char* s) {
    textConstruct(this, s);
}

inline Text::~Text() {
    textDestroy(this);
}

struct Owner;

struct Object {
    virtual void reserved() = 0;
    virtual void setText(const Text&) = 0;
    void attach(Owner*);
};

struct Shared {
    Object* object;
    Control* control;
    Shared(const Shared&, int);
    ~Shared();
};

inline Shared::Shared(const Shared& other, int)
    : object(other.object), control(other.control) {
    if (control)
        _InterlockedIncrement(&control->strong);
}

inline Shared::~Shared() {
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

extern Shared __cdecl obtain(void*);

struct Owner {
    Object* create(const char*, void*);
};

Object* Owner::create(const char* name, void* argument) {
    Shared value(obtain(argument), 0);
    {
        Text text(name);
        value.object->setText(text);
    }
    value.object->attach(this);
    return value.object;
}

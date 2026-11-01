// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct String;
extern void (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

inline String::String(const char* text) {
    stringConstruct(this, text);
}

inline String::~String() {
    stringDestroy(this);
}

struct S;

struct Object {
    char storage[0x178];
    void attach(S*);
};

struct Named {
    virtual void reserved() = 0;
    virtual void setName(const String&) = 0;
};

struct Result {
    Object* object;
    Control* control;
    Result(const Result&);
    ~Result();
    const Result& reference() const;
};

inline const Result& Result::reference() const {
    return *this;
}

inline Result::Result(const Result& other)
    : object(other.object), control(other.control) {
    if (control)
        _InterlockedIncrement(&control->strong);
}

inline Result::~Result() {
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

Result __cdecl createObject(unsigned int);

struct S {
    Object* f(const char*, unsigned int);
};

Object* S::f(const char* name, unsigned int kind) {
    Result result(createObject(kind).reference());
    reinterpret_cast<Named*>(result.object)->setName(String(name));
    result.object->attach(this);
    return result.object;
}

// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct String;
extern void (__thiscall* string_destructor)(String*);

struct String {
    unsigned long storage[7];
    ~String();
};

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

struct Value {
    virtual ~Value();
};

struct Holder {
    Value* value;
    Holder(const String&);
    ~Holder();
    void assign(const Shared&);
};

struct Arguments {
    unsigned long prefix[3];
    Holder* begin;
    Holder* end;
    Holder* capacity;
    Arguments(unsigned int);
    ~Arguments();
};

struct Receiver {
    virtual void unused() = 0;
    virtual void invoke(const Arguments&) = 0;
};

struct S {
    Receiver* receiver;
    void f(String, Shared);
};

__forceinline void* operator new(unsigned int, void* p)
{
    return p;
}

__forceinline String::~String()
{
    string_destructor(this);
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

__forceinline Holder::~Holder()
{
    if (value)
        delete value;
}

void S::f(String name, Shared instance)
{
    Arguments arguments(2);
    void (__cdecl* error)() = invalid_parameter_noinfo;

    if (static_cast<unsigned int>(arguments.end - arguments.begin) <= 0)
        error();

    Holder* first = arguments.begin;
    unsigned long storage;
    Holder* result = new (&storage) Holder(name);

    if (result != first) {
        Value* saved = result->value;
        result->value = first->value;
        first->value = saved;
    }
    reinterpret_cast<Holder*>(&storage)->~Holder();

    if (static_cast<unsigned int>(arguments.end - arguments.begin) <= 1)
        error();

    arguments.begin[1].assign(instance);
    receiver->invoke(arguments);
}

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

inline void add_ref(volatile long* count)
{
    _InterlockedExchangeAdd(count, 1);
}

struct Control {
    void* vtable;
    volatile long count;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        add_ref(&control->count);
}

struct FunctionTable {
    void (__cdecl *manage)(const void*, void*, int);
};

struct Function {
    FunctionTable* table;
    unsigned long padding;
    unsigned char storage[24];

    Function(const Function&);
    ~Function();
};

inline Function::Function(const Function& other)
    : table(0)
{
    if (other.table) {
        table = other.table;
        other.table->manage(other.storage, storage, 0);
    }
}

typedef void (__cdecl *Callback)(Function, void*, Shared);

struct S {
    void* object;
    Shared shared;

    void f(unsigned long, Callback*, Function* const*, unsigned long);
};

void S::f(unsigned long, Callback* callback,
          Function* const* function, unsigned long)
{
    (*callback)(**function, object, shared);
}
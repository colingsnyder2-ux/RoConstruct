// from server: 100% by Intel_Inside

void* __cdecl operator new(unsigned int size);

struct Bound {
    ~Bound();
    int storage[12];
};

struct Functor {
    int head[2];
    Bound bound;
};

bool __cdecl has_empty_target(const Functor* f);
void __cdecl construct(Functor* p, const Functor& value);

typedef void* (*Manager)();
typedef void (*Invoker)();

void* manage();
void invoke();

struct Function {
    Manager manager;
    void* functor;
    Invoker invoker;

    void assign_to(Functor f, int);
};

void Function::assign_to(Functor f, int)
{
    if (!has_empty_target(&f)) {
        invoker = &invoke;
        manager = &manage;
        Functor* copy = (Functor*)operator new(sizeof(Functor));
        construct(copy, f);
        functor = copy;
    }
}

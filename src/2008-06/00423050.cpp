// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Target {
    int invoke(int, int);
};

struct Service {
    char padding[0x130];
    Target* target;
    int invoke(int, int);
};

struct Result {
    int get();
};

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;

    volatile long strong;
    volatile long weak;
};

struct Shared {
    Service* object;
    Control* control;

    ~Shared();
};

struct Input {
    char padding[0x1c];
    int value;
};

Shared __cdecl acquire();

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

int __cdecl function(Input* input)
{
    Shared shared = acquire();
    int value = input->value;
    Result* result = reinterpret_cast<Result*>(
        shared.object->invoke(value, 1));
    return result ? result->get() : 0;
}

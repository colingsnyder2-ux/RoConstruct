// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern char instanceType;
extern char partType;

extern "C" void* __cdecl castObject(void*, long, void*, void*, int);
void __cdecl callback();

struct Instance {
    void fallback(void (__cdecl*)());
};

struct Part {
    void process();
};

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    Instance* pointer;
    Control* control;
    ~Shared();
};

inline Shared::~Shared() {
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

void __cdecl function_005a2330(Shared value) {
    Instance* instance = value.pointer;
    Part* part = static_cast<Part*>(
        castObject(instance, 0, &instanceType, &partType, 0));
    if (part)
        part->process();
    else
        instance->fallback(callback);
}

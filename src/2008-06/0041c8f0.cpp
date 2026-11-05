// from server: 100% by king_originala
struct Shared {
    unsigned int object;
    unsigned int control;
    ~Shared();
};

struct Argument {
    unsigned int prefix[2];
    Shared shared;
    unsigned char remainder[36];
};

extern bool __cdecl func_0060a2f0(...);
extern void* __cdecl allocate(unsigned int);
extern void __cdecl construct(void*, const Argument*);

struct S {
    const void* manager;
    unsigned int reserved;
    void* storage;

    S(Argument value);
};

S::S(Argument value)
{
    manager = 0;
    if (!func_0060a2f0(&value)) {
        void* p = allocate(48);
        construct(p, &value);
        storage = p;
        manager = reinterpret_cast<const void*>(0x0080ee30);
    } else {
        manager = 0;
    }
}

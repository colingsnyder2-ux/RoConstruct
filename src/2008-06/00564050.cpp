// from server: 100% by king_originala
struct Holder {
    virtual ~Holder();
};

struct HolderData {
    void* vtable;
    unsigned int padding;
    double value;
};

extern "C" void* __cdecl getDescriptor();
extern "C" void* __cdecl allocate(unsigned int);
extern unsigned int holderVtable[];

struct S {
    void* descriptor;
    Holder* held;

    S* f(const double* value);
};

S* S::f(const double* value)
{
    descriptor = getDescriptor();
    Holder** slot = &held;

    HolderData* p = static_cast<HolderData*>(allocate(16));
    if (p) {
        p->vtable = holderVtable;
        p->value = *value;
    } else {
        p = 0;
    }

    value = reinterpret_cast<const double*>(p);
    Holder* old = reinterpret_cast<Holder*>(p);
    if (reinterpret_cast<void*>(&value) != reinterpret_cast<void*>(slot)) {
        old = *slot;
        *slot = reinterpret_cast<Holder*>(p);
    }
    if (old)
        delete old;

    return this;
}

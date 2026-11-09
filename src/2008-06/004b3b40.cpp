// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct S;

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Reference {
    Control* control;
    Reference& operator=(const Reference&);
};

struct Object {
    void attach(S*);
};

struct Pair {
    Object* object;
    Reference reference;
    ~Pair();
};

inline Pair::~Pair()
{
    if (reference.control)
        reference.control->release();
}

Pair __cdecl make_pair();
unsigned int __cdecl get_index();
void __cdecl cleanup();
extern unsigned int cleanup_data;
void __cdecl register_cleanup(void (__cdecl*)(), unsigned int*);

struct S {
    unsigned char padding[0x19c];
    Pair* begin;
    Pair* end;

    Object* lookup();
    Object* get();
};

Object* S::get()
{
    Object* result = lookup();
    if (!result) {
        Pair value = make_pair();
        result = value.object;
        register_cleanup(cleanup, &cleanup_data);
        unsigned int index = get_index();
        if (index >= static_cast<unsigned int>(end - begin))
            _invalid_parameter_noinfo();
        Pair* slot = begin + index;
        slot->object = value.object;
        slot->reference = value.reference;
        result->attach(this);
    }
    return result;
}

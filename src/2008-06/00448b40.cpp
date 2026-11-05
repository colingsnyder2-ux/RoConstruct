// from server: 100% by king_originala
extern char registrationState;
extern void __cdecl registerEnum();
extern void __cdecl registerOnce(void (__cdecl*)(), void*);
extern void* __cdecl getEnum();
extern void* __cdecl getDescriptor();
extern void __cdecl releaseObject(void*);

struct Owner {
    void* pointer;

    Owner(void*);
    ~Owner();
    void* release();
};

inline Owner::Owner(void* value) : pointer(value)
{
}

inline Owner::~Owner()
{
    if (pointer)
        releaseObject(pointer);
}

inline void* Owner::release()
{
    void* result = pointer;
    pointer = 0;
    return result;
}

extern Owner __cdecl makeBinding(unsigned long, unsigned long,
                                unsigned long, unsigned long);

struct PropertyBase {
    virtual void slot();
    char padding[20];

    PropertyBase(void*, void*, const char*, const char*, unsigned long);
    ~PropertyBase();
};

struct EnumBase : PropertyBase {
    void* enumeration;

    EnumBase(const char*, const char*, unsigned long, void*, void*);
};

inline EnumBase::EnumBase(const char* name, const char* category,
                         unsigned long flags, void* descriptor, void* type)
    : PropertyBase(descriptor, type, name, category, flags),
      enumeration(type)
{
}

struct Descriptor : EnumBase {
    Owner binding;
    void* enumDescriptor;

    virtual void slot();
    Descriptor(const char*, const char*, unsigned long, unsigned long,
               unsigned long, unsigned long, unsigned long);
};

Descriptor::Descriptor(const char* name, const char* category,
                       unsigned long getter1, unsigned long getter2,
                       unsigned long setter1, unsigned long setter2,
                       unsigned long flags)
    : EnumBase(name, category, flags, getDescriptor(),
               (registerOnce(registerEnum, &registrationState), getEnum())),
      binding(makeBinding(getter1, getter2, setter1, setter2).release())
{
    registerOnce(registerEnum, &registrationState);
    enumDescriptor = getEnum();
}

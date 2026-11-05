// from server: 100% by king_originala
extern unsigned char registrationState;
extern void __cdecl initialize();
extern void __cdecl registerInitializer(void (__cdecl*)(), void*);
extern void* __cdecl getEnumTable();
extern void* __cdecl getClassDescriptor();

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base {
    unsigned char storage[20];

    Base(void*, void*, const char*, unsigned int, unsigned int);
    virtual ~Base();
};

struct EnumBase : Base {
    void* enumeration;

    EnumBase(void*, void*, const char*, unsigned int, unsigned int);
};

inline EnumBase::EnumBase(void* owner, void* table, const char* name,
                         unsigned int flags, unsigned int category)
    : Base(owner, table, name, flags, category), enumeration(table)
{
}

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();

    unsigned int getter;
    unsigned int setter;

    Setter(unsigned int, unsigned int);
};

inline Setter::Setter(unsigned int get, unsigned int set)
    : getter(get), setter(set)
{
}

struct Descriptor : EnumBase {
    Setter* access;

    virtual ~Descriptor();
    Descriptor(const char*, unsigned int, unsigned int,
               unsigned int, unsigned int);
};

Descriptor::Descriptor(const char* name, unsigned int flags,
                       unsigned int getter, unsigned int setter,
                       unsigned int category)
    : EnumBase(getClassDescriptor(),
               (registerInitializer(initialize, &registrationState),
                getEnumTable()),
               name, flags, category)
{
    access = new Setter(getter, setter);
}

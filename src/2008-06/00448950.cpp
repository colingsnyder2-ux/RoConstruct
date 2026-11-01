// from server: 100% by king_originala
extern void __cdecl registerType(void (__cdecl*)(), void*);
extern void __cdecl initializeType();
extern char typeStorage;
extern void* __cdecl enumType();
extern void* __cdecl classType();
extern void* descriptorVtable[];
void __cdecl operator delete(void*);

struct Value {};

struct Transfer {
    mutable Value* pointer;

    Value* release() const;
    ~Transfer();
};

inline Value* Transfer::release() const
{
    Value* result = pointer;
    pointer = 0;
    return result;
}

inline Transfer::~Transfer()
{
    if (pointer)
        delete pointer;
}

struct Owner {
    Value* pointer;

    Owner(const Transfer&);
    ~Owner();
};

inline Owner::Owner(const Transfer& other)
    : pointer(other.release())
{
}

inline Owner::~Owner()
{
    if (pointer)
        delete pointer;
}

extern Transfer __cdecl createValue(int, int, int, int);

struct Base {
    void* vtable;
    char padding[0x14];

    void initialize(void*, void*, int, int, int);
    ~Base();
    Base(void*, int, int, int);
};

inline Base::Base(void* type, int name, int category, int attributes)
{
    void* cls = classType();
    initialize(cls, type, name, category, attributes);
}

struct EnumBase : Base {
    void* enumeration;

    EnumBase(int, int, int, void*);
};

inline EnumBase::EnumBase(int name, int category, int attributes, void* type)
    : Base(type, name, category, attributes),
      enumeration(type)
{
}

struct Descriptor : EnumBase {
    Owner value;
    void* type;

    Descriptor(int, int, int, int, int, int, int);
    ~Descriptor();
};

Descriptor::Descriptor(int name, int category, int a, int b,
                       int c, int d, int attributes)
    : EnumBase(name, category, attributes,
               (registerType(initializeType, &typeStorage), enumType())),
      value((vtable = descriptorVtable, createValue(a, b, c, d)))
{
    registerType(initializeType, &typeStorage);
    type = enumType();
}

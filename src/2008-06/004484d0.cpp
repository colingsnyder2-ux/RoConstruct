// from server: 100% by king_originala
extern void __cdecl registerEnum(void (__cdecl*)(), void*);
extern void __cdecl initializeEnum();
extern unsigned char enumStorage;
extern void* __cdecl getEnumDescriptor();
extern void* __cdecl getClassDescriptor();
extern void __cdecl destroyProperty(void*);

struct Owner {
    void* pointer;

    explicit Owner(void*);
    ~Owner();
    void* release();
};

inline Owner::Owner(void* value) : pointer(value)
{
}

inline Owner::~Owner()
{
    if (pointer)
        destroyProperty(pointer);
}

inline void* Owner::release()
{
    void* result = pointer;
    pointer = 0;
    return result;
}

extern Owner __cdecl makeProperty(unsigned, unsigned, unsigned, unsigned);

struct __declspec(novtable) Base {
    virtual ~Base();
    unsigned char padding[20];
    void* enumDescriptor;

    Base(unsigned, unsigned, unsigned);
    void initialize(void*, void*, unsigned, unsigned, unsigned);
};

inline Base::Base(unsigned name, unsigned attributes, unsigned security)
{
    registerEnum(initializeEnum, &enumStorage);
    void* descriptor = getEnumDescriptor();
    void* classDescriptor = getClassDescriptor();
    initialize(classDescriptor, descriptor, name, attributes, security);
    enumDescriptor = descriptor;
}

struct Descriptor : Base {
    Owner property;
    void* enumType;

    Descriptor(unsigned, unsigned, unsigned, unsigned,
               unsigned, unsigned, unsigned);
    virtual ~Descriptor();
};

Descriptor::Descriptor(unsigned name, unsigned attributes,
                       unsigned getter0, unsigned getter1,
                       unsigned setter0, unsigned setter1,
                       unsigned security)
    : Base(name, attributes, security),
      property(makeProperty(getter0, getter1, setter0, setter1).release())
{
    registerEnum(initializeEnum, &enumStorage);
    enumType = getEnumDescriptor();
}

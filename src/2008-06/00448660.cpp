// from server: 100% by king_originala
extern void __cdecl initialize(void (__cdecl*)(), void*);
extern void __cdecl initializeType();
extern unsigned char typeStorage;
extern void* __cdecl getType();
extern void* __cdecl getEnum();
extern void __cdecl destroyObject(void*);

struct Owner {
    void* pointer;

    Owner(void*);
    ~Owner();
    void* release();
};

__forceinline Owner::Owner(void* p) : pointer(p)
{
}

__forceinline Owner::~Owner()
{
    if (pointer)
        destroyObject(pointer);
}

__forceinline void* Owner::release()
{
    void* result = pointer;
    pointer = 0;
    return result;
}

extern Owner __cdecl makeAccessor(unsigned, unsigned, unsigned, unsigned);

struct Base {
    virtual ~Base();
    unsigned data[5];

    Base(void*, void*, unsigned, unsigned, unsigned);
};

struct EnumBase : Base {
    void* type;

    EnumBase(void*, unsigned, unsigned, unsigned, void* = 0);
};

__forceinline EnumBase::EnumBase(void* t, unsigned a, unsigned b,
                                unsigned flags, void* enumValue)
    : Base(enumValue, t, a, b, (enumValue = getEnum(), flags)),
      type(t)
{
}

struct Descriptor : EnumBase {
    Owner accessor;
    void* enumMap;

    virtual ~Descriptor();
    Descriptor(unsigned, unsigned, unsigned, unsigned,
               unsigned, unsigned, unsigned);
};

Descriptor::Descriptor(unsigned a, unsigned b, unsigned c, unsigned d,
                       unsigned e, unsigned f, unsigned flags)
    : EnumBase(
          (initialize(initializeType, &typeStorage), getType()),
          a, b, flags),
      accessor(makeAccessor(c, d, e, f).release())
{
    initialize(initializeType, &typeStorage);
    enumMap = getType();
}

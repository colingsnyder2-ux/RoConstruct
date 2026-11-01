// from server: 100% by king_originala
void __cdecl registerEnum(void (__cdecl *)(), void *);
void *__cdecl getEnum();
void *__cdecl getSettings();
extern "C" void __cdecl destroyObject(void *);

struct Owner {
    void *pointer;

    Owner(void *);
    ~Owner();
    void *release();
};

inline Owner::Owner(void *value) : pointer(value)
{
}

inline Owner::~Owner()
{
    if (pointer)
        destroyObject(pointer);
}

inline void *Owner::release()
{
    void *result = pointer;
    pointer = 0;
    return result;
}

Owner __cdecl makeAccessor(
    unsigned long, unsigned long, unsigned long, unsigned long);

struct Descriptor {
    virtual ~Descriptor();
    unsigned long data[5];

    Descriptor(void *, void *, const char *, const char *, unsigned long);
};

struct EnumDescriptor : Descriptor {
    void *enumType;

    EnumDescriptor(void *, void *, const char *, const char *, unsigned long);
    ~EnumDescriptor();
};

inline EnumDescriptor::EnumDescriptor(
    void *settings, void *type, const char *name,
    const char *category, unsigned long flags)
    : Descriptor(settings, type, name, category, flags),
      enumType(type)
{
}

struct S : EnumDescriptor {
    Owner accessor;
    void *cachedEnum;

    S(const char *, const char *,
      unsigned long, unsigned long, unsigned long, unsigned long,
      unsigned long);
    virtual ~S();
};

S::S(const char *name, const char *category,
     unsigned long a, unsigned long b,
     unsigned long c, unsigned long d, unsigned long flags)
    : EnumDescriptor(
          getSettings(),
          (registerEnum(
               reinterpret_cast<void (__cdecl *)()>(0x60b840),
               reinterpret_cast<void *>(0x97bda8)),
           getEnum()),
          name, category, flags),
      accessor(makeAccessor(a, b, c, d).release())
{
    registerEnum(
        reinterpret_cast<void (__cdecl *)()>(0x60b840),
        reinterpret_cast<void *>(0x97bda8));
    cachedEnum = getEnum();
}

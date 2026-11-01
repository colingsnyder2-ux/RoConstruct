// from server: 100% by king_originala
struct Triple {
    unsigned long x, y, z;
};

extern "C" void __cdecl register_type(void (__cdecl *)(), void *);
extern "C" void *__cdecl get_descriptor();
void *__cdecl get_base_descriptor();
void __cdecl free_object(void *);

struct Owner {
    void *p;
    explicit Owner(void *);
    Owner(Owner &);
    ~Owner();
    void *release();
};

__forceinline Owner::Owner(void *value) : p(value)
{
}

__forceinline Owner::Owner(Owner &other) : p(other.release())
{
}

__forceinline Owner::~Owner()
{
    if (p)
        free_object(p);
}

__forceinline void *Owner::release()
{
    void *value = p;
    p = 0;
    return value;
}

extern Owner __cdecl make_property(Triple, Triple);

struct Base {
    void *vtable;
    char padding[20];

    Base(void *, void *, unsigned long, unsigned long);
    void initialize(void *, void *, void *, unsigned long, unsigned long);
    ~Base();
};

__forceinline Base::Base(
    void *value, void *name, unsigned long attributes, unsigned long flags)
{
    void *baseDescriptor = get_base_descriptor();
    initialize(baseDescriptor, value, name, attributes, flags);
}

struct DescriptorBase : Base {
    void *descriptor;
    DescriptorBase(void *, void *, unsigned long, unsigned long);
};

__forceinline DescriptorBase::DescriptorBase(
    void *value, void *name, unsigned long attributes, unsigned long flags)
    : Base(value, name, attributes, flags),
      descriptor(value)
{
}

__forceinline void *registered_descriptor()
{
    register_type(
        reinterpret_cast<void (__cdecl *)()>(0x0059c7e0),
        reinterpret_cast<void *>(0x00976644));
    return get_descriptor();
}

struct S : DescriptorBase {
    Owner property;
    void *classDescriptor;

    S(void *, unsigned long, Triple, Triple, unsigned long);
    ~S();
};

S::S(void *name, unsigned long attributes, Triple first, Triple second,
     unsigned long flags)
    : DescriptorBase(registered_descriptor(), name, attributes, flags),
      property((vtable = reinterpret_cast<void *>(0x008330cc),
                make_property(first, second).release())),
      classDescriptor(registered_descriptor())
{
}

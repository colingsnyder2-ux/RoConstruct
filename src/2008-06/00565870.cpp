// from server: 100% by king_originala
void __cdecl operator delete(void *);

extern unsigned descriptorState;
extern void __cdecl registerDescriptor(void (__cdecl *)(), void *);
extern void __cdecl descriptorInitializer();
extern void *__cdecl primaryDescriptor();
extern void *__cdecl secondaryDescriptor();

struct Owner {
    void *pointer;
    Owner(void *);
    ~Owner();
    void *release();
};

__forceinline Owner::Owner(void *p) : pointer(p) {}

__forceinline Owner::~Owner()
{
    if (pointer)
        operator delete(pointer);
}

__forceinline void *Owner::release()
{
    void *result = pointer;
    pointer = 0;
    return result;
}

extern Owner __cdecl makeProduct(unsigned, unsigned, unsigned, unsigned);

struct Base {
    virtual ~Base();
    unsigned storage[5];
    Base(void *, void *, unsigned, unsigned, unsigned);
};

struct DescriptorBase : Base {
    void *descriptor;
    DescriptorBase(void *, unsigned, unsigned, unsigned, void * = 0);
};

__forceinline DescriptorBase::DescriptorBase(void *p, unsigned a,
                                             unsigned b, unsigned g, void *q)
    : Base(q, p, a, b, (q = secondaryDescriptor(), g)), descriptor(p)
{
}

struct Product : DescriptorBase {
    Owner product;
    void *secondary;

    Product(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
    virtual ~Product();
};

static __forceinline void *registeredDescriptor()
{
    registerDescriptor(descriptorInitializer, &descriptorState);
    return primaryDescriptor();
}

Product::Product(unsigned a, unsigned b, unsigned c, unsigned d,
                 unsigned e, unsigned f, unsigned g)
    : DescriptorBase(registeredDescriptor(), a, b, g),
      product(makeProduct(c, d, e, f).release()),
      secondary(registeredDescriptor())
{
}

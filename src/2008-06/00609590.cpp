// from server: 100% by king_originala
extern "C" void __cdecl registerDescriptor(void (__cdecl *)(), void *);
extern "C" void __cdecl initializeDescriptor();
extern "C" void *__cdecl getDescriptor();
extern "C" void *__cdecl getModelDescriptor();
extern unsigned char descriptorStorage;

void __cdecl operator delete(void *);

struct Triple {
    unsigned int a, b, c;
};

struct Owned {
    void *p;
    explicit Owned(void *value) : p(value) {}
    ~Owned() {
        if (p)
            operator delete(p);
    }
    void *release() {
        void *value = p;
        p = 0;
        return value;
    }
};

extern Owned __cdecl makeProduct(Triple, Triple);

struct Base {
    unsigned int data[5];
    Base(void *, void *, const char *, const char *, int);
    virtual ~Base();
};

struct TypedBase : Base {
    void *type;
    TypedBase(void *, void *, const char *, const char *, int);
};

__forceinline TypedBase::TypedBase(
    void *model, void *descriptor, const char *name,
    const char *category, int flags)
    : Base(model, descriptor, name, category, flags),
      type(descriptor)
{
}

__forceinline void *descriptor()
{
    registerDescriptor(initializeDescriptor, &descriptorStorage);
    return getDescriptor();
}

struct S : TypedBase {
    Owned product;
    void *extra;

    S(const char *, const char *, Triple, Triple, int);
    virtual ~S();
};

S::S(const char *name, const char *category,
     Triple getter, Triple setter, int flags)
    : TypedBase(getModelDescriptor(), descriptor(), name, category, flags),
      product(makeProduct(getter, setter).release())
{
    extra = descriptor();
}

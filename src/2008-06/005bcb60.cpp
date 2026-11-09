// from server: 100% by king_originala
extern "C" void __cdecl registerType(void (__cdecl *)(), void*);
extern "C" void __cdecl typeCallback();
extern "C" void* __cdecl getType();
extern "C" void* __cdecl getRoot();
extern unsigned char typeData;

void __cdecl operator delete(void*);

struct TemporaryOwner {
    mutable int* pointer;

    int* release() const;
    ~TemporaryOwner();
};

inline int* TemporaryOwner::release() const
{
    int* p = pointer;
    pointer = 0;
    return p;
}

inline TemporaryOwner::~TemporaryOwner()
{
    if (pointer)
        operator delete(pointer);
}

struct Owner {
    int* pointer;

    Owner(const TemporaryOwner&);
    ~Owner();
};

inline Owner::Owner(const TemporaryOwner& other)
    : pointer(other.release())
{
}

inline Owner::~Owner()
{
    if (pointer)
        operator delete(pointer);
}

extern TemporaryOwner __cdecl makeOwner(unsigned int, unsigned int,
                                       unsigned int, unsigned int);

struct Base {
    unsigned char storage[0x14];

    Base(void*, void*, unsigned int, unsigned int, unsigned int);
    virtual ~Base();
};

struct TypedBase : Base {
    void* type;

    TypedBase(void*, void*, unsigned int, unsigned int, unsigned int);
};

inline TypedBase::TypedBase(void* root, void* descriptor,
                           unsigned int a, unsigned int b, unsigned int g)
    : Base(root, descriptor, a, b, g), type(descriptor)
{
}

struct S : TypedBase {
    Owner owner;
    void* finalType;

    S(unsigned int, unsigned int, unsigned int, unsigned int,
      unsigned int, unsigned int, unsigned int);
    virtual ~S();
};

S::S(unsigned int a, unsigned int b, unsigned int c, unsigned int d,
     unsigned int e, unsigned int f, unsigned int g)
    : TypedBase(getRoot(),
                (registerType(typeCallback, &typeData), getType()),
                a, b, g),
      owner(makeOwner(c, d, e, f))
{
    registerType(typeCallback, &typeData);
    finalType = getType();
}

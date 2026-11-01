// from server: 100% by king_originala
extern "C" void __cdecl registerName(void (__cdecl *)(), const char *);
extern "C" void __cdecl nameCallback();
extern const char nameText[];
extern void * __cdecl getName();
extern void * __cdecl getEnum();

struct Accessor {
    unsigned long words[4];
};

struct Owner {
    int *pointer;
    explicit Owner(int *);
    ~Owner();
    int *release();
};

inline Owner::Owner(int *p) : pointer(p)
{
}

inline Owner::~Owner()
{
    if (pointer)
        delete pointer;
}

inline int *Owner::release()
{
    int *p = pointer;
    pointer = 0;
    return p;
}

extern Owner __cdecl makeOwner(unsigned long, unsigned long,
                              unsigned long, unsigned long);

struct Base {
    unsigned char padding[20];
    Base(void *, void *, const char *, const char *, int);
    virtual ~Base();
};

struct NamedBase : Base {
    void *name;
    NamedBase(void *, void *, const char *, const char *, int);
};

inline NamedBase::NamedBase(void *e, void *n,
                           const char *a, const char *b, int flags)
    : Base(e, n, a, b, flags), name(n)
{
}

struct S : NamedBase {
    Owner owner;
    void *descriptor;
    S(const char *, const char *, Accessor, int);
    virtual ~S();
};

S::S(const char *a, const char *b, Accessor accessor, int flags)
    : NamedBase(getEnum(),
                (registerName(nameCallback, nameText), getName()),
                a, b, flags),
      owner(makeOwner(accessor.words[0], accessor.words[1],
                      accessor.words[2], accessor.words[3]).release())
{
    registerName(nameCallback, nameText);
    descriptor = getName();
}

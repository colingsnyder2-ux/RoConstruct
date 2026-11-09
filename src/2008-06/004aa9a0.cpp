// from server: 100% by king_originala
extern "C" void __cdecl registerType(void *, void *);
extern "C" void * __cdecl getDescriptor();
extern "C" void * __cdecl getCreator();

extern void *derivedTable[];

struct Owner {
    int *pointer;
    Owner(int *);
    Owner(const Owner &);
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

extern Owner __cdecl makeOwner(int, int, int, int);

struct Base {
    unsigned char data[24];
    void *descriptor;

    Base(int, int, int);
    ~Base();
    void initialize(void *, void *, int, int, int);
};

inline Base::Base(int a, int b, int g)
{
    registerType(reinterpret_cast<void *>(0x4aa700),
                 reinterpret_cast<void *>(0x971204));
    void *d = getDescriptor();
    void *creator = getCreator();
    initialize(creator, d, a, b, g);
    descriptor = d;
}

struct S : Base {
    Owner owned;
    void *secondary;

    S(int, int, int, int, int, int, int);
};

S::S(int a, int b, int c, int d, int e, int f, int g)
    : Base(a, b, g),
      owned((*reinterpret_cast<void ***>(this) = derivedTable,
             makeOwner(c, d, e, f).release()))
{
    registerType(reinterpret_cast<void *>(0x4aa700),
                 reinterpret_cast<void *>(0x971204));
    secondary = getDescriptor();
}

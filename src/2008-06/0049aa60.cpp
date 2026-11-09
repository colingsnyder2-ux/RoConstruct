// from server: 100% by king_originala
extern void* __cdecl getFirstDescriptor();
extern void* __cdecl getSecondDescriptor();
void __cdecl operator delete(void*);

extern const char primaryTable[];
extern const char secondaryTable[];

struct Owner {
    void* p;

    ~Owner();
    void* release();
};

inline Owner::~Owner()
{
    if (p)
        operator delete(p);
}

inline void* Owner::release()
{
    void* result = p;
    p = 0;
    return result;
}

extern Owner __cdecl makeOwner(int, int, int);

struct Base {
    const void* primary;
    char padding[20];
    const void* secondary;

    Base(int, int, int);
    void initialize(void*, void*, int, int, int);
    ~Base();
};

__forceinline Base::Base(int a, int b, int f)
{
    void* first = getFirstDescriptor();
    void* second = getSecondDescriptor();
    initialize(second, first, a, b, f);
}

struct S : Base {
    void* value;

    S(int, int, int, int, int, int);
};

S::S(int a, int b, int c, int d, int e, int f)
    : Base(a, b, f)
{
    primary = primaryTable;
    secondary = secondaryTable;
    value = makeOwner(c, d, e).release();
}

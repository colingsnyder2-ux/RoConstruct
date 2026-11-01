// from server: 100% by king_originala
extern void __cdecl registerType(void (__cdecl *)(), void *);
extern void __cdecl initializeType();
extern unsigned char typeStorage[];
extern const unsigned long motorTable[];
extern void *__cdecl getType();
extern void *__cdecl getSettings();
extern void __cdecl operator delete(void *);

struct Owned {
    void *pointer;

    Owned(Owned &);
    ~Owned();
};

__forceinline Owned::Owned(Owned &other)
{
    void *p = other.pointer;
    other.pointer = 0;
    pointer = p;
}

__forceinline Owned::~Owned()
{
    if (pointer)
        operator delete(pointer);
}

extern Owned __cdecl createMotor(int, int, int, int);

struct Base {
    unsigned char storage[0x18];
    void *type;

    Base(int, int, int);
    ~Base();
    void construct(void *, void *, int, int, int);
};

__forceinline Base::Base(int a, int b, int g)
{
    registerType(initializeType, typeStorage);
    void *t = getType();
    void *settings = getSettings();
    construct(settings, t, a, b, g);
    type = t;
}

struct S : Base {
    Owned motor;
    void *registeredType;

    S(int, int, int, int, int, int, int);
};

S::S(int a, int b, int c, int d, int e, int f, int g)
    : Base(a, b, g),
      motor((*(const unsigned long **)storage = motorTable,
             createMotor(c, d, e, f)))
{
    registerType(initializeType, typeStorage);
    registeredType = getType();
}

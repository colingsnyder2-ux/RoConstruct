// from server: 100% by king_originala
extern void __cdecl registerType(void (__cdecl *)(), void *);
extern void __cdecl typeInitializer();
extern unsigned char typeStorage;
extern void * __cdecl enumDescriptor();
extern void * __cdecl propertyDescriptor();
extern void __cdecl releaseObject(void *);

struct Temporary {
    mutable void *p;
    ~Temporary();
};

inline Temporary::~Temporary() {
    if (p)
        releaseObject(p);
}

struct Owned {
    void *p;
    Owned(const Temporary &);
    ~Owned();
};

inline Owned::Owned(const Temporary &other) {
    void *value = other.p;
    other.p = 0;
    p = value;
}

inline Owned::~Owned() {
    if (p)
        releaseObject(p);
}

extern Temporary __cdecl makeObject(int, int, int, int);

inline void *registeredDescriptor() {
    registerType(typeInitializer, &typeStorage);
    return enumDescriptor();
}

struct Base {
    unsigned char data[20];
    Base(void *, void *, int, int, int);
    virtual ~Base();
};

struct EnumBase : Base {
    void *descriptor;
    EnumBase(int, int, int, void * = registeredDescriptor(), void * = 0);
    ~EnumBase();
};

inline EnumBase::EnumBase(int a, int b, int g, void *desc, void *prop)
    : Base(prop, desc, a, b, (prop = propertyDescriptor(), g)),
      descriptor(desc) {
}

struct S : EnumBase {
    Owned object;
    void *type;
    S(int, int, int, int, int, int, int);
    virtual ~S();
};

S::S(int a, int b, int c, int d, int e, int f, int g)
    : EnumBase(a, b, g), object(makeObject(c, d, e, f)) {
    type = registeredDescriptor();
}

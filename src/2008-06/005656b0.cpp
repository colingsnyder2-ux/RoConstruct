// from server: 100% by king_originala
extern "C" void __cdecl registerType(void (__cdecl *)(), void *);
extern "C" void *__cdecl getDescriptor();
extern "C" void *__cdecl getEnum();
void __cdecl operator delete(void *);

struct Temporary {
    void *p;
    void *release() const;
    ~Temporary();
};

inline void *Temporary::release() const {
    void *result = p;
    const_cast<Temporary *>(this)->p = 0;
    return result;
}

inline Temporary::~Temporary() {
    if (p)
        operator delete(p);
}

struct Owner {
    void *p;
    Owner(const Temporary &);
    ~Owner();
};

inline Owner::Owner(const Temporary &other) : p(other.release()) {
}

inline Owner::~Owner() {
    if (p)
        operator delete(p);
}

extern Temporary __cdecl createObject(int, int, int, int);

struct Root {
    unsigned char storage[20];
    Root(void *, void *, int, int, int);
    virtual ~Root();
};

struct Base : Root {
    void *descriptor;
    Base(int, int, int,
         void * = getEnum(),
         void * = (registerType((void (__cdecl *)())0x565430,
                               (void *)0x9744b0),
                   getDescriptor()));
};

__forceinline Base::Base(int a, int b, int g, void *en, void *desc)
    : Root(en, desc, a, b, g), descriptor(desc) {
}

struct S : Base {
    Owner object;
    void *factory;
    S(int, int, int, int, int, int, int);
    virtual ~S();
};

S::S(int a, int b, int c, int d, int e, int f, int g)
    : Base(a, b, g), object(createObject(c, d, e, f)) {
    registerType((void (__cdecl *)())0x565430, (void *)0x9744b0);
    factory = getDescriptor();
}

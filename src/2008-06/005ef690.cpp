// from server: 100% by king_originala
extern "C" void __cdecl registerName(void (__cdecl *)(), const char *);
extern "C" void __cdecl nameCallback();
extern "C" void * __cdecl getDescriptor();
extern "C" void * __cdecl getType();
extern const char faceName[];
void __cdecl operator delete(void *);

struct Owner {
    void *value;
    explicit Owner(void *p) : value(p) {}
    ~Owner() {
        if (value)
            operator delete(value);
    }
    void *release() {
        void *p = value;
        value = 0;
        return p;
    }
};

extern Owner __cdecl makeOwner(int, int, int, int);

struct __declspec(novtable) Base {
    virtual ~Base();
    void initialize(void *, void *, int, int, int);

    int storage[5];
    void *descriptor;

    Base(int a, int b, int g) {
        registerName(nameCallback, faceName);
        void *p = getDescriptor();
        void *t = getType();
        initialize(t, p, a, b, g);
        descriptor = p;
    }
};

struct S : Base {
    Owner owner;
    void *descriptor2;

    S(int, int, int, int, int, int, int);
    virtual ~S();
};

S::S(int a, int b, int c, int d, int e, int f, int g)
    : Base(a, b, g), owner(makeOwner(c, d, e, f).release())
{
    registerName(nameCallback, faceName);
    descriptor2 = getDescriptor();
}

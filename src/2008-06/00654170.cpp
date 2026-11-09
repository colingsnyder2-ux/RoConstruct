// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);

struct Vector;

struct Proxy {
    Vector* owner;
    Proxy(Vector*);
};

inline Proxy::Proxy(Vector* p) : owner(p) {}

struct ProxyHolder {
    Proxy* proxy;
    ProxyHolder(Vector*);
    ~ProxyHolder();
};

inline ProxyHolder::ProxyHolder(Vector* p) : proxy(new Proxy(p)) {}

struct Vector : ProxyHolder {
    unsigned int unused[2];
    void* first;
    void* last;
    void* limit;

    Vector();
    Vector(const Vector&);
    ~Vector();
};

inline Vector::Vector()
    : ProxyHolder(this), first(0), last(0), limit(0)
{
    if (first)
        operator new(4);
}

struct S {
    void f(int);
    void g(int, Vector);
};

void S::f(int value)
{
    g(value, Vector());
}

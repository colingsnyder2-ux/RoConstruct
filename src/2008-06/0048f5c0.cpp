// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Product {
    virtual ~Product();
};

struct Deleter {
    void operator()(Product* p) const { delete p; }
};

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    virtual void* get_deleter(const void*);

    long strong;
    long weak;
    Product* object;
    Deleter deleter;

    Control(Product* p, Deleter d)
        : strong(1), weak(1), object(p), deleter(d) {}
};

struct S {
    Control* control;
    S(Product* p, Deleter d);
};

S::S(Product* p, Deleter d) : control(0)
{
    try {
        control = new Control(p, d);
    } catch (...) {
        d(p);
        throw;
    }
}

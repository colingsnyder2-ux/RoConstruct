// from server: 100% by king_originala
typedef unsigned int size_t;
void* __cdecl operator new(size_t);

struct Deleter {
    void operator()(void*) const;
};

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    virtual void* get_deleter(const void*);

    long uses;
    long weak;
    void* object;
    Deleter deleter;

    Control(void* p, Deleter d)
        : uses(1), weak(1), object(p), deleter(d) {}
};

struct S {
    Control* control;
    S(void*, Deleter);
};

S::S(void* p, Deleter d) : control(0)
{
    try {
        control = new Control(p, d);
    } catch (...) {
        d(p);
        throw;
    }
}

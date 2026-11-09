// from server: 100% by king_originala
void * __cdecl operator new(unsigned int);

extern void *controlTable[];

struct Deleter {
    void operator()(void *) const;
};

struct Control {
    void **table;
    long strong;
    long weak;
    void *pointer;
    unsigned char unused[4];

    Control(void *);
};

inline Control::Control(void *p)
    : table(controlTable), strong(1), weak(1), pointer(p)
{
}

struct S {
    Control *control;
    S(void *, Deleter);
};

S::S(void *p, Deleter d)
    : control(0)
{
    try {
        control = new Control(p);
    } catch (...) {
        d(p);
        throw;
    }
}

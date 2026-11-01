// from server: 100% by king_originala
void * __cdecl operator new(unsigned int);

struct Deleter {
    void operator()(void *) const;
};

struct ControlBlock {
    int strong;
    int weak;
    void *pointer;
    Deleter deleter;

    ControlBlock(void *, Deleter);
    virtual ~ControlBlock();
    virtual void dispose();
    virtual void destroy();
    virtual void *get_deleter(const void *);
};

inline ControlBlock::ControlBlock(void *p, Deleter d)
    : strong(1), weak(1), pointer(p), deleter(d)
{
}

struct SharedCount {
    ControlBlock *control;
    SharedCount(void *, Deleter);
};

SharedCount::SharedCount(void *p, Deleter d)
    : control(0)
{
    try {
        control = new ControlBlock(p, d);
    } catch (...) {
        d(p);
        throw;
    }
}

// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Deleter
{
    void operator()(void*) const;
};

struct ControlBlock
{
    virtual ~ControlBlock();
    virtual void dispose();
    virtual void destroy();
    virtual void* get_deleter(const void*);

    long strong;
    long weak;
    void* pointer;
    Deleter deleter;

    ControlBlock(void*, Deleter);
};

inline ControlBlock::ControlBlock(void* p, Deleter d)
    : strong(1), weak(1), pointer(p), deleter(d)
{
}

struct S
{
    ControlBlock* block;
    S(void*, Deleter);
};

S::S(void* p, Deleter d) : block(0)
{
    try
    {
        block = new ControlBlock(p, d);
    }
    catch (...)
    {
        d(p);
        throw;
    }
}

// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);

struct Deleter
{
    void operator()(void*) const;
};

struct Count
{
    virtual ~Count();
    virtual void dispose();
    virtual void destroy();
    virtual void* get_deleter(const void*);

    long strong;
    long weak;
    void* pointer;
    Deleter deleter;

    Count(void*, Deleter);
};

inline Count::Count(void* p, Deleter d)
    : strong(1), weak(1), pointer(p), deleter(d)
{
}

struct S
{
    Count* count;
    S(void*, Deleter);
};

S::S(void* p, Deleter d)
    : count(0)
{
    try
    {
        count = new Count(p, d);
    }
    catch (...)
    {
        d(p);
        throw;
    }
}

// from server: 100% by king_originala
struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct Base
{
    virtual ~Base();
};

struct Count
{
    Control *control;
    Count();
    ~Count();
};

inline Count::Count() : control(0)
{
}

inline Count::~Count()
{
    if (control)
        control->release();
}

struct S : Base
{
    void *value;
    Count count;
    void *first;
    void *last;

    S(void *, void *, void *);
    virtual ~S();
    void connect(void *);
};

S::S(void *a, void *b, void *c)
    : value(0), first(a), last(c)
{
    connect(b);
}

// from server: 90% by atomic.potato
struct Inner
{
    virtual int f(int);
    virtual int g(int);
    virtual int h(int);
};

struct Vec
{
    char pad[0x98];
    int* begin;
    int* end;
};

struct S
{
    char pad[0x20];
    Inner* inner;
    Vec* vec;
    int g(int);
};

int S::g(int a)
{
    int idx = inner->h(a);
    int count = (int)((vec->end - vec->begin) >> 2);
    if ((unsigned)idx < (unsigned)count)
        return vec->begin[idx];
    return -1;
}

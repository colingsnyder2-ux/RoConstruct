// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Counted
{
    virtual void f0();
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count) == 0)
            destroy();
    }
    void release()
    {
        if (_InterlockedDecrement(&use_count) == 0)
        {
            dispose();
            weak_release();
        }
    }
};

struct Count
{
    Counted* pi;
    void reset()
    {
        if (pi != 0)
            pi->release();
    }
};

struct Elem
{
    int a;
    int b;
    Count pn;
};

struct Q
{
    char pad[0x10];
    Elem** map;
    unsigned mapsize;
    unsigned off;
    unsigned size;
    void tidy();
};

void Q::tidy()
{
    while (size != 0)
    {
        if (size != 0)
        {
            unsigned b = off + size - 1;
            if (mapsize <= b)
                b -= mapsize;
            Count* c = &map[b]->pn;
            c->reset();
            if (--size == 0)
                off = 0;
        }
    }
    for (unsigned i = mapsize; 0 < i;)
    {
        --i;
        if (map[i] != 0)
            operator delete(map[i]);
    }
    if (map != 0)
        operator delete(map);
    mapsize = 0;
    map = 0;
}

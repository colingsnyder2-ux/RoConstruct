// from server: 71% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CountedBase {
    virtual void f0();
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
    void release()
    {
        if (_InterlockedExchangeAdd(&use_count, -1) == 1) {
            dispose();
            if (_InterlockedExchangeAdd(&weak_count, -1) == 1)
                destroy();
        }
    }
};

struct Alloc {
    void deallocate(char* p, unsigned n);
};

struct Buffer {
    char* p;
    unsigned n;
    ~Buffer()
    {
        if (p) {
            Alloc a;
            a.deallocate(p, n);
        }
    }
};

struct Opt {
    void* px;
    CountedBase* pi;
    bool init;
    ~Opt()
    {
        if (init) {
            if (pi)
                pi->release();
            init = false;
        }
    }
};

struct StreambufBase {
    char pad[0x40];
    ~StreambufBase();
};

struct S : StreambufBase {
    Opt storage;
    int m4c;
    Buffer buf;
    ~S();
};

S::~S()
{
}

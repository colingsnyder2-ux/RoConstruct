// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);

struct Deleter {
    void operator()(void*) const;
};

struct CountedBase {
    long use_count;
    long weak_count;

    CountedBase();
    virtual ~CountedBase();
    virtual void dispose() = 0;
    virtual void destroy();
    virtual void* get_deleter(const void*) = 0;
};

struct CountedBlock : CountedBase {
    void* pointer;
    Deleter deleter;

    CountedBlock(void*, Deleter);
    virtual ~CountedBlock();
    virtual void dispose();
    virtual void* get_deleter(const void*);
};

struct SharedCount {
    CountedBase* control;
    SharedCount(void*, Deleter);
};

__forceinline CountedBase::CountedBase()
    : use_count(1), weak_count(1)
{
}

__forceinline CountedBlock::CountedBlock(void* p, Deleter d)
    : pointer(p), deleter(d)
{
}

SharedCount::SharedCount(void* p, Deleter d)
    : control(0)
{
    try {
        control = new CountedBlock(p, d);
    }
    catch (...) {
        d(p);
        throw;
    }
}

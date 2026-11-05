// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Deleter {
    void operator()(void*) const;
};

struct CountBase {
    int strong;
    int weak;

    CountBase();
    virtual ~CountBase();
    virtual void dispose() = 0;
    virtual void destroy();
    virtual void* get_deleter(const void*) = 0;
};

inline CountBase::CountBase() : strong(1), weak(1) {}

struct Count : CountBase {
    void* pointer;
    Deleter deleter;

    Count(void*, Deleter);
    virtual ~Count();
    virtual void dispose();
    virtual void* get_deleter(const void*);
};

inline Count::Count(void* p, Deleter d) : pointer(p), deleter(d) {}

struct S {
    CountBase* count;
    S(void*, Deleter);
};

S::S(void* p, Deleter d) : count(0)
{
    try {
        count = new Count(p, d);
    }
    catch (...) {
        d(p);
        throw;
    }
}

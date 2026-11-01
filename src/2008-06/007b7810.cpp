// from server: 100% by king_originala
struct Ptr {
    void* value;
    Ptr(const Ptr& p);
    ~Ptr();
    void reset(void* p);
};

inline Ptr::Ptr(const Ptr& p)
{
    value = 0;
    reset(p.value);
}

struct S {
    char pad[12];
    Ptr value;
    Ptr f();
};

Ptr S::f()
{
    return Ptr(value);
}

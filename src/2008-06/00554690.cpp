// from server: 100% by king_originala
struct Callback {
    virtual void invoke(void *, void *, void *) = 0;
};

struct S {
    void f(void *, void *, Callback *);
};

void S::f(void *a, void *b, Callback *callback)
{
    volatile char scratch[40];
    try {
        void *owner = 0;
        if (this)
            owner = reinterpret_cast<char *>(this) - 0x170;
        callback->invoke(owner, a, b);
        __assume(0);
    }
    catch (...) {
        scratch[0] = 0;
    }
}

// from server: 22% by atomic.potato
struct Inner {
    char pad[4];
    void init();
};

struct S {
    char pad0[4];
    Inner inner;
    void* method(void* a, void* b);
};

void Inner::init() {}

void* S::method(void* a, void* b)
{
    inner.init();
    return a;
}

// from server: 11% by atomic.potato
struct Inner {
    char pad[4];
    void init(int);
};

struct Outer {
    Inner inner;
    void* func(int, int);
};

void Inner::init(int) {}

void* Outer::func(int a, int b)
{
    inner.init(1);
    return (void*)0;
}

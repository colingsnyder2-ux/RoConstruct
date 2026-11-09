// from server: 50% by atomic.potato
struct Inner {
    char pad[4];
    int method(int, int);
};

struct S {
    char pad[4];
    Inner* field4;
    void f();
};

void S::f()
{
    (field4 + 1)->method(0, 1);
}

// from server: 100% by why2
struct Inner {
    char pad[4];
    int method();
};

struct S {
    char pad[4];
    Inner* field4;
    int f();
};

int S::f()
{
    return (field4 + 1)->method();
}

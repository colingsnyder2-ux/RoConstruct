// from server: 100% by king_originala
struct State {
    char padding[0x1B4];
    int value;
};

struct Resolver {
    State* get(int);
};

struct S {
    char padding[0x10];
    Resolver resolver;
    bool f();
};

bool S::f()
{
    return resolver.get(1)->value == 1;
}

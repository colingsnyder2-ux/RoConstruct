// from server: 100% by king_originala
struct Tail {
    void invoke();
};

struct S {
    char padding[0x248];
    unsigned char dirty;
    char gap[0x1B];
    Tail tail;
    void f();
};

void S::f()
{
    dirty = 1;
    tail.invoke();
}

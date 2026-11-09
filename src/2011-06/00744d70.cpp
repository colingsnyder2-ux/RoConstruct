// from server: 21% by atomic.potato
struct Sub {
    char pad[4];
    void init(int);
};

struct S {
    char pad0[4];
    Sub sub;
    int f(int, int);
};

void Sub::init(int) {}

int S::f(int a, int b) {
    sub.init(1);
    return a;
}

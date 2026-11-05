// from server: 21% by atomic.potato
struct Sub {
    char pad[4];
    void init(int);
};

struct S {
    Sub sub;
    void* f(int, int);
};

void Sub::init(int) {}

void* S::f(int a, int b) {
    sub.init(1);
    return (void*)a;
}

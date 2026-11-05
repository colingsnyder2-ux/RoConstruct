// from server: 21% by atomic.potato
struct Inner {
    char pad[4];
    void method(int);
};

struct Outer {
    char pad0[4];
    Inner inner;
    int method(int, int);
};

void Inner::method(int) {}

int Outer::method(int a, int b) {
    int local = 0;
    inner.method(1);
    return a;
}

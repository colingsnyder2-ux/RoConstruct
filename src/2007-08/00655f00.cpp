// from server: 100% by colin
struct Inner {
    int f(int);
};

struct Outer {
    char pad[0xac];
    Inner* inner;
    int g(int);
};

int Outer::g(int x) {
    inner->f(x);
    return x;
}

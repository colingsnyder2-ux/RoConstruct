// from server: 21% by atomic.potato
struct Inner {
    virtual double f(int);
};

struct Outer {
    char pad[0x1c];
    Inner* inner;
    double g(int);
};

double Outer::g(int a) {
    double d = inner->f(a);
    return d;
}

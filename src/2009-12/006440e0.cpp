// from server: 50% by atomic.potato
struct Inner {
    virtual int f(int);
};

struct Outer {
    char pad[0x1c];
    Inner* inner;
    int g(int, char*);
};

int Outer::g(int a, char* out) {
    int r = inner->f(a);
    *out = (char)r;
    return (int)out;
}

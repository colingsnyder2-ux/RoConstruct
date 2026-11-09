// from server: 58% by atomic.potato
struct Inner {
    virtual int f(int** out, int arg);
};

struct Outer {
    char pad[0x28];
    Inner* inner;
    int method(int arg);
};

int Outer::method(int arg) {
    int* out;
    int r = inner->f(&out, arg);
    out[0] = 0;
    return r;
}

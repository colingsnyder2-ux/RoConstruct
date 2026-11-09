// from server: 50% by atomic.potato
struct Inner {
    virtual void f(int, int*);
};

struct Outer {
    char pad[0x1c];
    Inner* inner;
    int method(int, int*);
};

extern "C" void __cdecl sub_651C20(int, int*);

int Outer::method(int a, int* b) {
    int tmp = 0;
    inner->f(a, &tmp);
    sub_651C20(tmp, b);
    return tmp;
}

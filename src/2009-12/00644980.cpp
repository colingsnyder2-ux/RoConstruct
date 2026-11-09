// from server: 50% by atomic.potato
extern "C" void __stdcall sub_6b1890(int, int*);

struct Inner {
    virtual void f(int, int*);
};

struct Outer {
    char pad[0x1c];
    Inner* inner;
    int method(int, int*);
};

int Outer::method(int a, int* b) {
    int tmp = 0;
    inner->f(a, &tmp);
    sub_6b1890(tmp, &tmp);
    return tmp;
}

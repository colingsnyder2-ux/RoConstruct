// from server: 42% by atomic.potato
struct Inner {
    virtual void f(int, int*);
};

struct Outer {
    char pad[0x28];
    Inner* p;
    int get(int a);
};

int Outer::get(int a) {
    int result = 0;
    p->f(a, &result);
    return result;
}

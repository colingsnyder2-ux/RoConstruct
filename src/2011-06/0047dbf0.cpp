// from server: 100% by atomic.potato
struct Inner {
    void method(int);
};

struct Outer {
    char pad[0xc];
    Inner* inner;
};

int __stdcall func(Outer* p) {
    Inner* inner = p->inner;
    if (!inner) return 0x80004005;
    inner->method(1);
    return 0;
}

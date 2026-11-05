// from server: 32% by atomic.potato
struct Inner {
    int field0;
    int init(int);
};

struct EventDesc {
    char pad0[4];
    Inner inner;
    int init(int, int);
};

int Inner::init(int x) {
    field0 = 0;
    return x;
}

int EventDesc::init(int a, int b) {
    inner.init(1);
    return a;
}

// from server: 21% by atomic.potato
struct Sub {
    void init(int);
};

struct EventDesc {
    char pad0[4];
    Sub sub;
    int method(int, int);
};

void Sub::init(int) {}

int EventDesc::method(int a, int b) {
    sub.init(1);
    return a;
}

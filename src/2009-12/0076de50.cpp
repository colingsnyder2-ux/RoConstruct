// from server: 100% by atomic.potato
struct Inner {
    void Set(int);
};

struct Outer {
    char pad0[0xd4];
    Inner a;
    char pad1[0xfc - 0xd4 - 1];
    Inner b;
    char pad2[0x124 - 0xfc - 1];
    Inner c;
    void Func(int);
};

void Outer::Func(int x) {
    a.Set(x);
    b.Set(x);
    c.Set(x);
}

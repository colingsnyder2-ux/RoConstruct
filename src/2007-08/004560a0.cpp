// from server: 88% by colin
struct Inner {
    char pad[0xe0];
    char flag;
};

struct Mid {
    char pad[0x20];
    Inner* inner;
};

struct Outer {
    char pad[4];
    Mid* mid;
};

extern Outer* GetOuter();

struct S {
    char f();
};

char S::f() {
    return GetOuter()->mid->inner->flag;
}

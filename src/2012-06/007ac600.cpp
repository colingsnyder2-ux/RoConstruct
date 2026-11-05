// from server: 100% by tajop
struct Inner {
    void g(int a);
};

struct Lighting {
    char pad[0x1f0];
    Inner member;
    void f(int a);
};

void Lighting::f(int a) {
    member.g(0);
}

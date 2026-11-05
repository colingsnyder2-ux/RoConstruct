// from server: 1% by atomic.potato
struct Sub1 { void f(); };
struct Sub2 { void f(); };

struct Mesh {
    char pad0[0xc];
    Sub2 sub_c;
    char pad10[0x8];
    Sub2 sub_18;
    char pad1c[0x8];
    Sub2 sub_24;
    char pad28[0x8];
    Sub1 sub_30;
    void destroy();
};

void Sub1::f() {}
void Sub2::f() {}

void Mesh::destroy() {
    sub_30.f();
    sub_24.f();
    sub_18.f();
    sub_c.f();
    ((Sub2*)this)->f();
}

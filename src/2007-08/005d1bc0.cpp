// from server: 100% by colin
struct Sub {
    void method();
};

struct Tool {
    char pad[0x1cc];
    Sub sub1cc;
    char pad2[0x1e0 - 0x1cc - sizeof(Sub)];
    Sub sub1e0;
    void func();
};

void Tool::func() {
    sub1cc.method();
    sub1e0.method();
}

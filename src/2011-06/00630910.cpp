// from server: 100% by tester
struct Sub {
    void method();
};

struct Tool {
    char pad[0x238];
    Sub sub1cc;
    char pad2[0x23c - 0x238 - sizeof(Sub)];
    Sub sub1e0;
    void func();
};

void Tool::func() {
    sub1cc.method();
    sub1e0.method();
}

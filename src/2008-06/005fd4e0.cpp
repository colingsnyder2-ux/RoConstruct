// from server: 100% by tester
struct Sub {
    void method();
};

struct Tool {
    char pad[0x240];
    Sub sub1cc;
    char pad2[0x254 - 0x240 - sizeof(Sub)];
    Sub sub1e0;
    void func();
};

void Tool::func() {
    sub1cc.method();
    sub1e0.method();
}

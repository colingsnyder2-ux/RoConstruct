// from server: 100% by tester
struct S {
    char pad[0x48];
    char flag;
    void f();
};

extern "C" void __cdecl helper();

void S::f() {
    if (flag != 0) {
        helper();
        flag = 0;
    }
}

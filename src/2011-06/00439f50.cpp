// from server: 100% by colin
struct S {
    char pad[0x10c];
    char flag;
    void f();
};

extern "C" void __stdcall sub_439A50(int);
extern "C" void __stdcall sub_439B40();

void S::f() {
    if (flag != 0) {
        sub_439A50(0);
        return;
    }
    sub_439B40();
}

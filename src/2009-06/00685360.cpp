// from server: 100% by why2
struct S {
    char pad[4];
    unsigned char flag;
    void f();
};

void S::f() {
    if (flag != 0) {
        flag = 0;
    }
}

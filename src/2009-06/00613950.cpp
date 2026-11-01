// from server: 100% by why2
struct S {
    char pad[1];
    char flag;
    void f();
};

void S::f() {
    if (this->flag != 0) {
        this->flag = 0;
    }
}

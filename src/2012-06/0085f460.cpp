// from server: 90% by intel
struct Inner {
    void Method();
    char pad[0x48];
    char flag;
};

struct Outer {
    Inner* ptr;
    void func();
};

void Outer::func() {
    Inner* p = ptr;
    if (p->flag) {
        p->Method();
        p->flag = 0;
    }
}

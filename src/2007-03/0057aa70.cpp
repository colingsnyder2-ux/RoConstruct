// from server: 100% by tester
struct Inner {
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12(int);
};

struct Outer {
    Inner* ptr;
    void func();
};

void Outer::func() {
    Inner* p = ptr;
    if (p) {
        p->vfunc12(1);
    }
}

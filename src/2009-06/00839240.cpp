// from server: 100% by why2
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct Outer {
    char pad[0x6c];
    Inner* field_6c;
    void f();
};

void Outer::f() {
    Inner* p = field_6c;
    p->v5();
}

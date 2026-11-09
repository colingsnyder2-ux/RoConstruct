// from server: 100% by why2
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
};

struct Outer {
    char pad[0x6c];
    Inner* field_6c;
    void f();
};

void Outer::f() {
    Inner* p = field_6c;
    p->v17();
}

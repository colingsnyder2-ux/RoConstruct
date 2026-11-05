// from server: 100% by king_originala
struct Interface {
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
    virtual void apply(void*, int);
    virtual bool ready();
};

struct S {
    char padding[0x140];
    Interface* object;

    void finish();
    void f(void*);
};

void S::f(void* argument) {
    if (object->ready())
        object->apply(argument, 0);
    finish();
}

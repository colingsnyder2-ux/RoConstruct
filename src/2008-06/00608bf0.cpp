// from server: 100% by king_originala
extern char instanceType;
extern char pvInstanceType;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

struct PVInstance {
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
    virtual void v18();
    virtual void v19();
    virtual void action();
};

struct S {
    char padding[0x104];
    void* instance;
    void f();
};

void S::f()
{
    PVInstance* p = (PVInstance*)__RTDynamicCast(
        instance, 0, &instanceType, &pvInstanceType, 0);
    if (p)
        p->action();
}

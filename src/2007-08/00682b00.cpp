// from server: 100% by colin
struct CXTPPropertyGrid {
    char pad[0x13c];
    struct Inner* m_pInner;
    void Func();
};

struct Inner {
    virtual void VFunc0();
    virtual void VFunc1();
    virtual void VFunc2();
    virtual void VFunc3();
    virtual void VFunc4();
    virtual void VFunc5();
    virtual void VFunc6();
    virtual void VFunc7();
    virtual void VFunc8();
    virtual void VFunc9();
    virtual void VFunc10();
    virtual void VFunc11();
    virtual void VFunc12();
    virtual void VFunc13();
};

extern void sub_738580();

void CXTPPropertyGrid::Func()
{
    sub_738580();
    m_pInner->VFunc13();
}

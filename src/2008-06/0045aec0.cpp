// from server: 100% by colin
struct S
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool check(int value);
    int f();
};

int S::f()
{
    if (check(0x131) || check(0x132))
        return 1;
    return 0;
}

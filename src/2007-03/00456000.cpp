// from server: 100% by tester
struct Inner {
    virtual void v0();
    virtual void v1(int);
};

struct Holder {
    char pad[0x28];
    Inner inner;
};

struct CRobloxWnd {
    Holder* field0;
    void func();
};

void CRobloxWnd::func()
{
    if (field0 != 0)
        field0->inner.v1(1);
}

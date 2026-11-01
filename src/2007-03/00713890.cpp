// from server: 100% by tester
struct CControlButtonHide {
    void Hide();
};

struct Inner {
    virtual void vfunc();
};

struct Outer {
    char pad[0xfc];
    Inner* inner;
};

void CControlButtonHide::Hide()
{
    Outer* o = (Outer*)this;
    Inner* p = o->inner;
    void** vtbl = *(void***)p;
    typedef void (__thiscall *Fn)(Inner*, int);
    Fn f = (Fn)vtbl[0x15c / 4];
    f(p, 0);
}

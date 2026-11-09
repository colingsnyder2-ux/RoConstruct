// from server: 100% by king_originala
struct S {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual bool key(int code) = 0;

    bool f();
};

bool S::f()
{
    return key(0x77) ||
           key(0x73) ||
           key(0x61) ||
           key(0x64) ||
           key(0x111) ||
           key(0x112) ||
           key(0x114) ||
           key(0x113);
}

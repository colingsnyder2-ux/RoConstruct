// from server: 100% by king_originala
struct Result {
    void* value;
    Result(void* p) : value(p) {}
};

struct Delegate {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual Result get(int);
};

struct S {
    unsigned char padding[8];
    Delegate* delegate;
    Result get(int);
};

Result S::get(int argument)
{
    Delegate* p = delegate;
    volatile int temporary = 0;
    if (!p)
        return Result(p);
    return p->get(argument);
}

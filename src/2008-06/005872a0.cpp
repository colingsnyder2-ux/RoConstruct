// from server: 100% by king_originala
struct Callback {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void invoke(void *, void *);
};

struct Argument {
    Callback *callback;
    unsigned char data[1];
};

struct S {
    void *reserved;
    unsigned char *object;
    void f(Argument *);
};

void S::f(Argument *arg)
{
    void *p = object ? object + 20 : 0;
    arg->callback->invoke(p, arg->data);
}

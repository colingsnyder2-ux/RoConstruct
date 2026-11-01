// from server: 100% by king_originala
struct Receiver {
    virtual void slot0();
    virtual void submit(int value);
    int m_x;
    void f(int a1);
};

struct S {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int value();
    void f(Receiver *receiver);
};

void S::f(Receiver *receiver)
{
    receiver->f((int)this);
    receiver->submit(value());
}

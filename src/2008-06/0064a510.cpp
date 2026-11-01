// from server: 100% by king_originala
struct Stage;

struct S_func_00645820 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct Receiver {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void process(S_func_00645820*);
};

struct Stage {
    virtual void slot0();
    virtual int getValue();
    int pad4;
    Receiver* receiver;
    void f(S_func_00645820* arg);
};

void Stage::f(S_func_00645820* arg)
{
    int value = reinterpret_cast<Stage*>(arg->m_x)->getValue();
    if (value > getValue())
        receiver->process(arg);
    arg->f(reinterpret_cast<int>(this));
}

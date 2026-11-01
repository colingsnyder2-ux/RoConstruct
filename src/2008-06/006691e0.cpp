// from server: 100% by king_originala
struct Stage;

struct Argument {
    int field0;
    Stage *field4;
    void f(int);
};

struct Receiver {
    void f(Argument *);
};

struct InsertResult {
    unsigned int data[3];
};

struct Container {
    InsertResult insert(Argument * const &);
};

struct Stage {
    virtual void slot0();
    virtual int priority();

    int field4;
    Receiver *field8;
    char padding0[8];
    unsigned char dirty;
    char padding1[35];
    Container container;

    void f(Argument *);
};

void Stage::f(Argument *arg)
{
    if (arg->field4 != 0) {
        int otherPriority = arg->field4->priority();
        if (otherPriority > priority()) {
            field8->f(arg);
            Argument *value = arg;
            container.insert(value);
            dirty = 1;
        }
    }
}

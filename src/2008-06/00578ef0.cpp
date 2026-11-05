// from server: 100% by colin
struct Object
{
    char padding[20];
    char value;

    void setFirst(int);
    void clear();
    void setSecond(int);
    void update();
    void stop();
    void finish();
};

struct Dispatcher
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void dispatch(void*, const bool&);
};

struct Pair
{
    void* v;
    bool f;
};

extern Dispatcher* dispatcher;

struct S
{
    char padding[0x204];
    Object* first;
    char gap[12];
    Object* second;

    Object* getFirst();
    Object* getSecond();
    Object* getThird();
    Object* getFourth();
    Object* getLast();
    void f();
};

void S::f()
{
    first->setFirst(0);
    first->clear();
    first->setSecond(0);
    second->clear();

    Object* p = getFirst();
    if (p)
        p->clear();

    p = getSecond();
    if (p)
        p->update();

    p = getThird();
    if (p)
        p->stop();

    p = getFourth();
    if (p)
        p->clear();

    p = getLast();
    if (p)
    {
        p->finish();
        Pair pr = { &p->value, false };
        void* value = pr.v;
        bool flag = pr.f;
        dispatcher->dispatch(value, flag);
    }
}

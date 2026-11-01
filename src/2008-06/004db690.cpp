// from server: 100% by king_originala
extern const double value;

struct Source {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void set(double);
};

struct Query {
    virtual void slot0();
    virtual void slot1();
    virtual int get();
};

struct Target {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void apply(int, int);
};

struct Context {
    char padding[0x288];
    Query query;
};

struct Holder {
    char padding[0x204];
    Context* context;
};

struct S {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void prepare();

    Source* source;
    Target* target;
    char padding[8];
    Holder* holder;

    void f(int);
};

void S::f(int arg) {
    prepare();
    source->set(value);
    Context* c = holder->context;
    Target* t = target;
    t->apply(arg, c->query.get());
}

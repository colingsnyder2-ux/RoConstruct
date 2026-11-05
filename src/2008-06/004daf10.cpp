// from server: 100% by king_originala
struct Source {
    virtual void slot0();
    virtual void slot1();
    virtual int get();
};

struct Container {
    char padding[0x288];
    Source source;
};

struct Context {
    char padding[0x204];
    Container* container;
};

struct Sink;
typedef void (__thiscall *SetFunction)(Sink*, int, int);

struct Sink {
    SetFunction* table;
};

struct S {
    char padding0[8];
    Sink* sink;
    char padding1[8];
    Context* context;

    void prepare(int);
    void f(int);
};

void S::f(int value)
{
    prepare(value);
    Container* container = context->container;
    Sink* destination = sink;
    SetFunction* entry = destination->table + 5;
    int result = container->source.get();
    (*entry)(destination, value, result);
}

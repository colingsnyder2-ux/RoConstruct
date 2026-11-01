// from server: 100% by king_originala
struct Resource {
    void* object;
    void* control;

    Resource() : object(0), control(0) {}
    ~Resource();
};

struct Guard {
    Resource resource;
    int state;

    Guard(void* p) : state(0) { acquire(p); }
    void acquire(void*);
    ~Guard();
};

struct Interface {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void apply(void*, void*) = 0;
};

struct Provider {
    char padding[0x198];
    void* content;
};

struct Destination {
    char padding[0x18];
    Interface* target;
};

struct Argument {
    char padding[0x14];
    char payload;
};

struct S {
    char padding[0x128];
    Provider* provider;
    Destination* destination;

    void* f(void*, Argument*);
};

void* S::f(void* result, Argument* argument)
{
    Guard guard(provider->content);
    void* payload = argument ? &argument->payload : 0;
    register Destination* dest = destination;
    dest->target->apply(result, payload);
    return result;
}

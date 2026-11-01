// from server: 100% by colin
//

struct Handle {
    int first;
    int second;
    Handle() : first(0), second(0) {}
    ~Handle();
};

struct Temporary {
    Handle handle;
    int third;
    void init(int value);
    Temporary(int value) : third(0) { init(value); }
    ~Temporary();
};

struct Source {
    char padding[0x198];
    int value;
};

struct Receiver {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void invoke(void* value, int argument);
};

struct Destination {
    char padding[0x18];
    Receiver* receiver;
};

struct S {
    char padding[0x13c];
    Source* source;
    Destination* destination;
    void f(void* value, int argument);
};

void S::f(void* value, int argument)
{
    Temporary temporary(source->value);
    char* p = static_cast<char*>(value);
    if (p != 0)
        p += 0x14;
    else
        p = 0;
    Destination* d = destination;
    Receiver* r = d->receiver;
    r->invoke(p, argument);
}

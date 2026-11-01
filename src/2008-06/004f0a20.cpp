// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

struct Control {
    virtual ~Control();
    volatile long references;
    void release();
};

struct Temporary {
    Control *control;
    Temporary();
    ~Temporary();
};

inline Temporary::Temporary() : control(0) {}

inline Temporary::~Temporary()
{
    if (control && InterlockedDecrement(&control->references) == 0) {
        control->release();
        if (control)
            delete control;
    }
}

struct Value {
    unsigned long data[3];
};

struct Result {
    unsigned long data;
    ~Result();
};

struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual Result get(const Value &, Temporary &);
};

struct S {
    unsigned long reserved;
    Interface *object;
    Result get(Value);
};

Result S::get(Value value)
{
    Temporary temporary;
    return object->get(value, temporary);
}

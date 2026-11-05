// from server: 100% by king_originala
struct Buffer {
    void *first;
    void *last;
    void *limit;

    Buffer();
    ~Buffer();
    void initialize(int);
};

inline Buffer::Buffer() : first(0), last(0) {}

struct Temporary {
    Buffer buffer;

    Temporary(int);
};

inline Temporary::Temporary(int value)
{
    buffer.limit = 0;
    buffer.initialize(value);
}

struct Source {
    char padding[0x198];
    int value;
};

struct Receiver {
    virtual void slot0();
    virtual void slot1();
    virtual bool apply(void *);
};

struct Destination {
    char padding[0x18];
    Receiver *receiver;

    bool apply(void *);
};

__forceinline bool Destination::apply(void *value)
{
    return receiver->apply(value);
}

struct Argument {
    char padding[0x14];
    char value;
};

struct S {
    char padding[0x13c];
    Source *source;
    Destination *destination;

    bool f(Argument *);
};

bool S::f(Argument *argument)
{
    Temporary temporary(source->value);
    return destination->apply(argument ? &argument->value : 0);
}

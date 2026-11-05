// from server: 100% by king_originala
struct TemporaryBase {
    unsigned int words[3];
    TemporaryBase();
    ~TemporaryBase();
};

inline TemporaryBase::TemporaryBase()
{
    words[0] = 0;
    words[1] = 0;
}

struct Temporary : TemporaryBase {
    void initialize(void*);
    Temporary(void*);
};

inline Temporary::Temporary(void* p)
{
    words[2] = 0;
    initialize(p);
}

struct Source {
    char padding[0x198];
    void* value;
};

struct Argument {
    char padding[0x14];
};

struct Receiver {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual int apply(void*);
};

struct Item {
    char padding[0x130];
    Source* source;
    Receiver* receiver;
    int evaluate(Argument*);
};

int Item::evaluate(Argument* argument)
{
    Temporary temporary(source->value);
    return receiver->apply(argument ? argument->padding + 0x14 : 0);
}

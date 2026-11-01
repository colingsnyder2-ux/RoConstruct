// from server: 100% by king_originala
struct Getter {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual bool get(void* object) = 0;
};

struct Value {
    unsigned int reserved;
    unsigned int type;
    bool data;

    void clear();
};

struct Output {
    char reserved[16];
    Value value;
};

struct S {
    char reserved[24];
    Getter* getter;

    void f(void* object, Output* output);
};

void S::f(void* object, Output* output)
{
    bool result = getter->get(object);
    Value* value = &output->value;
    value->clear();
    value->data = result;
    value->type = 4;
}

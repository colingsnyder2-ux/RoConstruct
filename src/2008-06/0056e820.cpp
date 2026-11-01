// from server: 100% by king_originala
struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual int get(void* object);
};

struct Value {
    unsigned char padding[4];
    int tag;
    int value;
    void clear();
};

struct Output {
    unsigned char padding[16];
    Value data;
};

struct S {
    unsigned char padding[24];
    Accessor* accessor;
    void f(void* object, Output* output);
};

void S::f(void* object, Output* output)
{
    int value = accessor->get(object);
    Value* data = &output->data;
    data->clear();
    data->value = value;
    data->tag = 5;
}

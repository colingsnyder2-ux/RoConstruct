// from server: 100% by king_originala
struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual double get(void*);
};

struct Variant {
    unsigned int storage;
    unsigned int type;
    double value;

    void clear();
};

struct Output {
    unsigned char padding[16];
    Variant variant;
};

struct S {
    unsigned char padding[24];
    Getter* getter;

    void get(void*, Output*);
};

void S::get(void* object, Output* output)
{
    double value = getter->get(object);
    Variant* result = &output->variant;
    result->clear();
    result->value = value;
    result->type = 9;
}

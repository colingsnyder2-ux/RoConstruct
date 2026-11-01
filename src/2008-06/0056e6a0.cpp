// from server: 100% by king_originala
struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual float get(void *object);
};

struct Value {
    unsigned int reserved;
    int type;
    float number;
    void clear();
};

struct Result {
    unsigned char padding[16];
    Value value;
};

struct S {
    unsigned char padding[24];
    Getter *getter;
    void read(void *object, Result *result);
};

void S::read(void *object, Result *result)
{
    float number = getter->get(object);
    Value *value = &result->value;
    value->clear();
    value->number = number;
    value->type = 7;
}

// from server: 100% by colin
struct Value {
    bool toFloat(float* result);
};

struct Variant {
    char padding[16];
    Value value;
    bool isEmpty();
};

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* object, const float& value);
};

struct Descriptor {
    char padding[24];
    Setter* setter;
    void apply(void* object, Variant* value, int unused);
};

void Descriptor::apply(void* object, Variant* value, int unused)
{
    if (!value->isEmpty()) {
        float result;
        if (value->value.toFloat(&result))
            setter->set(object, result);
    }
}

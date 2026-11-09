// from server: 100% by king_originala
struct Result {
    char data[0x24];
};

struct Provider {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual Result compute(float value) = 0;
};

struct Source {
    void set(float value);
    void consume(const Result& value);
};

struct Primitive {
    char reserved0[0x9c];
    Provider* provider;
    Source* source;
    char reserved1[0x4c];
    char changed;

    void func_005e8000(float value);
};

void Primitive::func_005e8000(float value)
{
    source->set(value);
    source->consume(provider->compute(value));
    changed = 1;
}

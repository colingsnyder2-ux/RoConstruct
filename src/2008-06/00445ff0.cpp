// from server: 100% by king_originala
struct Value {
    float convert();
};

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void *, const float &);
};

struct S {
    char padding[24];
    Setter *setter;
    void f(void *, Value *);
};

void S::f(void *object, Value *value)
{
    float &converted = reinterpret_cast<float &>(value);
    converted = value->convert();
    setter->set(object, converted);
}

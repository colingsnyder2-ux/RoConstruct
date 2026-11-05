// from server: 100% by king_originala
struct Input {
    int convert();
};

struct Binding {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, int*);
};

struct S {
    unsigned char padding[28];
    Binding* binding;

    void f(void*, Input*);
};

void S::f(void* object, Input* value)
{
    value = reinterpret_cast<Input*>(value->convert());
    binding->set(object, reinterpret_cast<int*>(&value));
}

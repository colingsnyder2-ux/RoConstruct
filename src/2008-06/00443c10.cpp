// from server: 100% by king_originala
struct Value {
    void* convert();
};

struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* get(void*, void**);
};

struct S {
    unsigned char padding[24];
    Accessor* accessor;
    void* f(void* result, void* object);
};

void* S::f(void* result, void* object)
{
    object = static_cast<Value*>(object)->convert();
    return accessor->get(result, &object);
}

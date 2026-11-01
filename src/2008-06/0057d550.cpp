// from server: 100% by king_originala
struct Subobject {
    virtual void first();
    virtual void second();
};

struct S {
    char padding[0x130];
    Subobject subobject;
};

void f(S* object)
{
    object->subobject.second();
}

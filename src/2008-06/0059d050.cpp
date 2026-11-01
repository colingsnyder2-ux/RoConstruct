// from server: 100% by king_originala
extern void* __cdecl operator new(unsigned int);
extern void __cdecl operator delete(void*);
extern int __cdecl getType();

struct Base {};

struct Prefix {
    char padding[0x134];
};

struct Object : Prefix, virtual Base {};

struct Holder {
    virtual ~Holder();
    float value;

    Holder(float v) : value(v) {}
};

struct Result {
    int type;
    Holder* value;
};

struct Descriptor {
    char padding[0x38];
    float (Object::*method)();

    void invoke(Object* object, Result* result);
};

void Descriptor::invoke(Object* object, Result* result)
{
    float value = (object->*method)();
    result->type = getType();

    Holder*& destination = result->value;
    Holder* replacement = new Holder(value);
    if (&replacement != &destination) {
        Holder* old = destination;
        destination = replacement;
        replacement = old;
    }
    if (replacement)
        delete replacement;
}

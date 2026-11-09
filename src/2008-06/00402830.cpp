// from server: 100% by king_originala
struct Interface0 {
    virtual void f0();
};

struct Interface1 {
    virtual void f1();
};

struct Interface2 {
    virtual void f2();
    unsigned long data;
};

struct Interface3 {
    virtual void f3();
    unsigned long data;
};

struct Interface4 {
    virtual void f4();
};

struct Interface5 {
    virtual void f5();
};

struct InnerBase :
    Interface0, Interface1, Interface2,
    Interface3, Interface4, Interface5
{
    InnerBase();
    ~InnerBase();
};

struct Inner : InnerBase {
    void* argument;

    Inner(void* value);
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Module {
    virtual void first() = 0;
    virtual void second() = 0;
};

extern Module* module;

struct ObjectBase {
    unsigned long references;
    ObjectBase();
};

struct Object : ObjectBase {
    Inner inner;

    virtual void function();
    Object(void* argument);
};

inline ObjectBase::ObjectBase()
    : references(0)
{
}

inline Inner::Inner(void* value)
    : InnerBase(), argument(value)
{
}

Object::Object(void* argument)
    : ObjectBase(), inner(argument)
{
    module->second();
}

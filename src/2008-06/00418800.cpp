// from server: 100% by king_originala
struct InterfaceA {
    virtual void methodA();
};

struct InterfaceB {
    virtual void methodB();
};

struct InnerBase : InterfaceA, InterfaceB {
    void *owner;
    InnerBase();
    ~InnerBase();
};

struct Inner : InnerBase {
    virtual void methodA();
    virtual void methodB();
    Inner(void *);
};

struct Module {
    virtual void unused();
    virtual long lock();
};

extern Module *module;

struct Base {
    long references;
    Base();
};

struct S : Base {
    virtual void method();
    Inner contained;
    S(void *);
};

__forceinline Base::Base() : references(0)
{
}

__forceinline Inner::Inner(void *p)
{
    owner = p;
}

S::S(void *p) : contained(p)
{
    module->lock();
}

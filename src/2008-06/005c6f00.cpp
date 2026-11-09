// from server: 100% by king_originala
struct S {
    char pad[0x3b0];
    void* field_3b0;
    void* field_3b4;
    void f();
    void activate(void*);
};

struct Owner {
    char pad[0x204];
    S* target;
};

struct Tool {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool enabled();
    virtual void v4();
    virtual void* value();

    char pad[8];
    Owner* owner;

    void f(int);
};

void Tool::f(int) {
    if (enabled()) {
        owner->target->f();
    } else {
        S* target = owner->target;
        target->activate(value());
    }
}

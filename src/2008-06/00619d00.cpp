// from server: 100% by king_originala
struct Input {
    char padding[8];
    int key;
};

struct Owner {
    void set(int value);
};

struct Tool {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void cancel();

    char padding[0x44];
    Owner* owner;

    Tool* handle(const Input* input);
};

Tool* Tool::handle(const Input* input)
{
    if (input->key == 0x7f || input->key == 0x1b) {
        cancel();
        if (owner)
            owner->set(0);
        return 0;
    }
    return this;
}

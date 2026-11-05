// from server: 100% by king_originala
struct Result {
    int first;
    int second;
};

struct Event {
    int kind;
};

struct Object {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void release();
};

struct Holder {
    Object* object;
    void* control;
    void reset();
};

struct ChatEnter {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void update();

    char padding[0x130];
    Holder holder;
    char padding2[8];
    int state;

    Result handle(const Event& event);
};

Result ChatEnter::handle(const Event& event)
{
    if (holder.object)
        holder.object->release();

    holder.reset();

    if (state == 3) {
        if (event.kind == 4) {
            state = 1;
            update();
        }
    } else {
        if (event.kind == 4) {
            state = 3;
            update();
        }
    }

    Result result;
    result.second = 0;
    result.first = 1;
    return result;
}

// from server: 100% by colin
struct Link {
    virtual void unused();
    virtual int type();

    Link* parent;
    int padding;
    int active;
};

struct State {
    char padding[0xcc];
    float value;

    void update();
};

struct S {
    int padding0;
    Link* parent;
    char padding1[0x80];
    State* state;
    float value;

    void setValue(float);
};

// roc-flags: /O2 /GS- /EHsc /MD /fp:fast

void S::setValue(float v)
{
    if (value != v) {
        value = v;
        if (parent) {
            Link* p = parent->type() == 7 ? parent->parent : parent;
            if (p->active) {
                State* s = state;
                s->value = v;
                s->update();
            }
        }
    }
}

#pragma float_control(pop)

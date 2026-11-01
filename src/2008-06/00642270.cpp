// from server: 100% by king_originala
struct Action {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual bool enabled() = 0;
    virtual void slot3() = 0;
    virtual void execute(void*) = 0;
};

struct Argument {
    char padding[0x14];
    void* value;
};

struct VerbWidget {
    char padding[0x148];
    Action* action;
    void invoke(Argument*);
};

void VerbWidget::invoke(Argument* argument)
{
    if (action && action->enabled())
        action->execute(argument->value);
}

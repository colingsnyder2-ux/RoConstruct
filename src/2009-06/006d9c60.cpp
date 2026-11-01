// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S;

struct Arg
{
    void* unused;
    S* stage;
    void touch();
};

struct S
{
    virtual void slot0();
    virtual int rank();

    char padding[0x1f0];
    bool pending;

    void onRemove(Arg*);
    void onAdd(Arg*);
    void func(Arg*, bool);
};

static inline bool downstream(Arg* e, S* b)
{
    return e->stage && b && e->stage->rank() >= b->rank();
}

void S::func(Arg* arg, bool enable)
{
    if (downstream(arg, this))
    {
        arg->touch();
        if (enable)
        {
            pending = true;
            onAdd(arg);
        }
        else
        {
            onRemove(arg);
        }
    }
}

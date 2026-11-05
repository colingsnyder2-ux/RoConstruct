// from server: 100% by king_originala
struct Value;
struct Input
{
    int get();
};

typedef bool (__thiscall *Evaluator)(void*);

struct Value
{
    char padding[0x68];
    bool cached;
    bool dirty;
    char alignment[2];
    int adjustment;
    Evaluator evaluate;
    char* object;

    void update(int argument);
};

struct S
{
    virtual void slot0();
    virtual int rank();

    int padding;
    S* parent;

    void prepare();
    void notify(Value* value, int argument);
    void f(Input* input);
};

void S::f(Input* input)
{
    parent->prepare();

    Value* value = reinterpret_cast<Value*>(input->get());
    if (value->dirty)
    {
        value->cached = value->evaluate(value->object + value->adjustment);
        value->dirty = false;
    }

    bool previous = value->cached;
    value->update(reinterpret_cast<int>(input));

    if (value->dirty)
    {
        value->cached = value->evaluate(value->object + value->adjustment);
        value->dirty = false;
    }

    if (previous != value->cached)
    {
        S* stage = this;
        while (stage->rank() != 5)
            stage = stage->parent;
        stage->notify(value, 0);
    }
}

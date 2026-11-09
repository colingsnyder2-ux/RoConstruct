// from server: 100% by king_originala
struct Frame
{
    float data[12];
};

struct Value
{
    Frame *get(Frame *storage);
};

struct Accessor
{
    typedef void (__thiscall *Setter)(Accessor *, void *, const Frame *);
    Setter *table;
};

struct S
{
    char padding[24];
    Accessor *accessor;

    void f(void *object, Value *value);
};

void S::f(void *object, Value *value)
{
    Frame storage;
    Accessor *target = accessor;
    Accessor::Setter *slot = target->table + 3;
    const Frame *frame = value->get(&storage);
    (*slot)(target, object, frame);
}

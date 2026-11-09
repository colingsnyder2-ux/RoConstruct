// from server: 82% by atomic.potato
struct TreeStage;

struct VTable
{
    int (__thiscall *get)(void *, int);
};

struct Inner
{
    VTable *vtable;
};

struct TreeStage
{
    int field24;
    Inner *field8;
    int get(int);
};

int TreeStage::get(int value)
{
    if (value != 3)
        return field8->vtable->get(field8, value);

    return field24;
}

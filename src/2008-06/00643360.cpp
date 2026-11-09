// from server: 100% by king_originala
extern float factor;

struct Value
{
    char padding[8];
    float value;
};

struct Node
{
    char padding[0x9c];
    Value* data;
};

struct Owner
{
    void* first();
    int* second();
    int third();
};

struct S
{
    char padding0[8];
    Owner* owner;
    char padding1[0x24];
    float base;

    double f();
};

double S::f()
{
    float result = base;

    if (owner->first())
        result += ((Node*)owner->first())->data->value * factor;

    if (owner->second())
        return (double)((Node*)owner->second())->data->value + result;

    if (owner->third())
        return (double)((Node*)owner->third())->data->value + result;

    return result;
}

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern float factor;
struct Value { char padding[8]; float value; };
struct Prim { char padding[0xe0]; Value* data; };
struct Part { char padding[0x118]; Prim* prim; };
struct Owner
{
    Prim* first();
    Part* second();
    Part* third();
};
struct S
{
    char padding0[8];
    Owner* owner;
    char padding1[0x2c];
    float base;
    double f();
};
double S::f()
{
    float result = base;
    if (Prim* p = owner->first())
        result += p->data->value * factor;
    if (Part* p = owner->second())
        if (p->prim)
            return (double)p->prim->data->value + result;
    if (Part* p = owner->third())
        if (p->prim)
            return (double)p->prim->data->value + result;
    return result;
}

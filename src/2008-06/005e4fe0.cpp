// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern char property_0097ab74;

struct State
{
    char padding[0x90];
    float value;
};

struct S
{
    char padding[0x150];
    State* state;

    void setValue(float value);
    void notify(const void* property);
};

void S::setValue(float value)
{
    if (value != state->value)
    {
        state->value = value;
        notify(&property_0097ab74);
    }
}

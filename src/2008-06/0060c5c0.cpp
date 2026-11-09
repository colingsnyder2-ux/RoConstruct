// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern char property;

struct Value {
    char padding[0x94];
    float value;
};

struct S {
    char padding[0x150];
    Value* data;
    void notify(const void*);
    void setValue(float);
};

void S::setValue(float value)
{
    if (value != data->value) {
        data->value = value;
        notify(&property);
    }
}

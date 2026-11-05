// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
struct PropertyDescriptor;
extern const PropertyDescriptor prop_value;
struct Data { char pad[0xa4]; float value; };
struct Instance {
    void raisePropertyChanged(const PropertyDescriptor& d);
};
struct C : Instance {
    char pad[0xac];
    Data* data;
    void setValue(float v);
};
void C::setValue(float v)
{
    if (v != data->value) {
        data->value = v;
        raisePropertyChanged(prop_value);
    }
}

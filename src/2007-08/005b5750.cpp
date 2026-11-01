// from server: 100% by colin
struct Primitive {
    char pad[0xac];
    int field0xac;
    void setSomething(int value);
};

int getDefaultValue();

void Primitive::setSomething(int value)
{
    if (value == 0)
        value = getDefaultValue();
    if (field0xac != value)
        field0xac = value;
}

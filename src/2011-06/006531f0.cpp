// from server: 48% by atomic.potato
struct S
{
    char padding[208];
    float value;

    void __thiscall f(float value);
};

void __cdecl SetGlobalValue(unsigned int);

void __thiscall S::f(float value)
{
    if (value != this->value)
    {
        this->value = value;
        SetGlobalValue(0xccd32c);
    }
}

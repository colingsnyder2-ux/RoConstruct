// from server: 57% by atomic.potato
extern "C" void __stdcall Next(float);

struct S
{
    char padding[0x198];
    float value;
    void f(float);
};

void S::f(float value)
{
    if (value != this->value)
    {
        this->value = value;
        Next(value);
    }
}

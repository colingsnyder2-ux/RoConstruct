// from server: 75% by atomic.potato
extern "C" void __cdecl NotifyChanged(int);

struct MotorFeature
{
    char padding[156];
    int value;
    void setValue(int);
};

void MotorFeature::setValue(int value)
{
    if (this->value != value)
    {
        this->value = value;
        NotifyChanged(0xe525d4);
    }
}

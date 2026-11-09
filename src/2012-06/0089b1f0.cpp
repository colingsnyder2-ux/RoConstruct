// from server: 43% by atomic.potato
struct MotorFeature
{
    int value;

    void __thiscall setValue(float value);
};

void __thiscall MotorFeature::setValue(float value)
{
    int *p = (int *)this->value;
    float oldValue = *(float *)((char *)p + 0xa8);

    if (!(value == oldValue))
    {
        *(float *)((char *)p + 0xa8) = value;
        *(int *)0xe52638 = 0xe52638;
    }
}

// from server: 37% by atomic.potato
extern "C" void __cdecl UpdateMotorFeature(void *, unsigned long);

struct MotorFeature
{
    int f(float);
};

int MotorFeature::f(float value)
{
    void *p = *(void **)((char *)this + 0xa8);
    float *target = (float *)((char *)p + 0xac);

    if (value != *target || value != value || *target != *target)
    {
        *target = value;
        UpdateMotorFeature((void *)0xe52704, 0);
    }

    return 0;
}

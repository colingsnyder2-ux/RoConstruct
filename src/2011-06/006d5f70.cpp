// from server: 63% by atomic.potato
struct Motor
{
    unsigned char padding[0xb4];
    void *field_b4;
    void f(float value);
};

extern "C" void __stdcall G1_func_00411f60(void *);

void Motor::f(float value)
{
    float *field = (float *)((unsigned char *)field_b4 + 0xa8);
    if (value != *field)
    {
        *field = value;
        G1_func_00411f60((void *)0x00cd1770);
    }
}

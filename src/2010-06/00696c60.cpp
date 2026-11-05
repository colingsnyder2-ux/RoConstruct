// from server: 45% by atomic.potato
extern "C" void G1_func_0040c470(int);

struct Motor6D
{
    float setValue(float);
};

float Motor6D::setValue(float value)
{
    float *p = *(float **)((char *)this + 0xb4);
    if (value != p[0xD4 / 4])
    {
        p[0xD4 / 4] = value;
        G1_func_0040c470(0xC1E7B8);
    }
    return value;
}

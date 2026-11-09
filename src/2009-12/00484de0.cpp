// from server: 76% by atomic.potato
struct GCamera
{
    void __thiscall getValue(float* out);
    char padding[36];
    float field24;
    float field28;
    float field2c;
};

void __thiscall GCamera::getValue(float* out)
{
    out[0] = field24;
    out[1] = field28;
    out[2] = field2c;
}

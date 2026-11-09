// from server: 32% by atomic.potato
extern "C" float g_b4c440;

struct VFrame {
    char pad_0000[0x1c4];
    float f1c4;
    float f1c8;
    float f1cc;
    char pad_01d0[0x10];
    float f1e0;
    void method(float* out);
};

void VFrame::method(float* out)
{
    float maxv = g_b4c440;
    float zero = 0.0f;
    float v = maxv - f1e0;
    if (zero < v)
    {
        if (v < maxv)
        {
        }
        else
        {
            v = maxv;
        }
    }
    else
    {
        v = zero;
    }
    out[0] = f1c4;
    out[1] = f1c8;
    out[2] = f1cc;
    out[3] = v;
}

// from server: 24% by atomic.potato
extern "C" int __stdcall sub_8f5ef1(float, float);

struct S
{
    char pad0[0x10];
    float f10;
    float f14;
    char pad18[4];
    float f1c;
    char pad20[0x10];
    float f30;
    float f34;
    char pad38[4];
    float f3c;

    float* func_008f95ef(float* out, int strideOut, float* in, int strideIn, S* xform, unsigned int count);
};

float* S::func_008f95ef(float* out, int strideOut, float* in, int strideIn, S* xform, unsigned int count)
{
    float* result = out;
    while (count > 0)
    {
        float a = xform->f10 * in[1] + in[0] * xform->f10;
        float b = xform->f14 * in[0] + in[1] * xform->f14;
        float c = xform->f1c * in[0] + in[1] * xform->f1c;
        out[0] = a + xform->f30;
        out[1] = b + xform->f34;
        float z = c + xform->f3c;
        if (sub_8f5ef1(z, 1.0f) == 0)
        {
            float inv = 1.0f / z;
            out[0] = out[0] * inv;
            out[1] = out[1] * inv;
        }
        in = (float*)((char*)in + strideIn);
        out = (float*)((char*)out + strideOut);
        --count;
    }
    return result;
}

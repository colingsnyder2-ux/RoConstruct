// from server: 36% by atomic.potato
struct S
{
    float x;
    float y;
    float z;
};

void f(S* out, const S* in)
{
    float k = *(const float*)0x9b1610;
    out->x = in->x;
    out->y = in->y;
    out->z = in->z;
    out->x = out->x;
    out->y = out->y;
    out->z = out->z;
}

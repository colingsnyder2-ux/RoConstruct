// from server: 6% by atomic.potato
struct seg_008b0000
{
    void f(float *dst, const float *src);
};

void seg_008b0000::f(float *dst, const float *src)
{
    dst[0] += src[0];
    dst[1] += src[1];
    dst[2] += src[2];
    dst[3] += src[3];
}

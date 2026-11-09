// from server: 80% by atomic.potato
struct S
{
    int unused;
    int value;
    float get(float *p);
};

float S::get(float *p)
{
    if (p)
        return *(float *)((char *)p + value - 28);
    return *(float *)value;
}

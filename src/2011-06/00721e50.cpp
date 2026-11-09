// from server: 70% by atomic.potato
struct S
{
    typedef float *(__thiscall *Getter)(void *, void *);
    void *target;
    Getter get;
    int offset;
    float f(void *out, void *value);
};

float S::f(void *out, void *value)
{
    char *p = (char *)value;
    if (p)
        p -= 0x1c;

    float *result = get(target, p + offset);
    *(float *)out = result[0];
    ((float *)out)[1] = result[1];
    return ((float *)out)[0];
}

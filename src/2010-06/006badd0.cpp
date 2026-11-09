// from server: 81% by atomic.potato
struct S
{
    typedef float *(__thiscall *Getter)(void *);
    int value;
    Getter function;
    int offset;
    void f(float *out, const float *value);
};

void S::f(float *out, const float *value)
{
    char *p = value ? (char *)value - 0x1c : 0;
    Getter getter = function;
    float *result = (float *)getter((char *)this->offset + (int)p);
    out[0] = result[0];
    out[1] = result[1];
}

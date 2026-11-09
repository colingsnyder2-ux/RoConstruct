// from server: 83% by atomic.potato
struct S {
    int f(float *, void *);
    int *a;
    int *b;
};

int S::f(float *out, void *value)
{
    typedef float *(__thiscall *Fn)(void *);
    void *p = value ? (char *)value - 0x1c : 0;
    Fn fn = (Fn)a;
    float *r = fn((char *)b + (int)p);
    out[0] = r[0];
    out[1] = r[1];
    return (int)out;
}

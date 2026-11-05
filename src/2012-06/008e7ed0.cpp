// from server: 63% by atomic.potato
struct S
{
    int f(void *, float *);
    int pad0;
    int pad1;
    int b;
    int a;
};

int S::f(void *p, float *v)
{
    char *q = p ? (char *)p - 28 : 0;
    float x = v[0];
    float y = v[1];
    return ((int (__thiscall *)(int, float, float))a)(b + (int)q, x, y);
}

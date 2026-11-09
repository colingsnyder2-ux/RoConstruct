// from server: 46% by atomic.potato
struct S
{
    int v00;
    char pad04[36];
    float v2c;
    float v30;
    void (__thiscall *v34)(S *);
    S *f(short *);
};

S *S::f(short *p)
{
    v2c = (float)p[4];
    v30 = (float)p[5];
    v34(this);
    return this;
}

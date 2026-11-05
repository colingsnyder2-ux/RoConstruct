// from server: 77% by atomic.potato
extern "C" void __stdcall glColor4fv(const float *);

struct S
{
    char pad0[8];
    float color[4];
    void f(float *);
};

void S::f(float *p)
{
    S *q = *(S **)((char *)this + 8);
    float *a = (float *)((char *)q + 0x4a8);
    a[0] = p[0];
    a[1] = p[1];
    a[2] = p[2];
    a[3] = p[3];
    glColor4fv(a);
}

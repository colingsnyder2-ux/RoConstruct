// from server: 28% by atomic.potato
struct S
{
    void f(float *);
};

extern "C" void __stdcall sub_40c470(int);

void S::f(float *p)
{
    float v = *p;
    float old = *(float *)((char *)this + 0x1d0);
    if (old == v || old < v || old > v)
        return;
    *(float *)((char *)this + 0x1d0) = v;
    sub_40c470(0x00c1d1b0);
}

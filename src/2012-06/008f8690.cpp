// from server: 96% by atomic.potato
struct S {
    int m10;
    int m14;
    int m18;
    void f(float a, float b, float c, float d);
};

typedef void (__thiscall *F)(int, float, float, float, float);

void S::f(float a, float b, float c, float d)
{
    F p = (F)*(void **)((char *)this + 0x10);
    p(m14 + m18, a, b, c, d);
}

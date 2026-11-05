// from server: 39% by atomic.potato
extern "C" void __cdecl call_007400a0(float *, int);

struct S
{
    void f(float, float);
};

void S::f(float a, float b)
{
    float v[2];
    v[0] = a;
    v[1] = b;
    call_007400a0(v, 4);
}

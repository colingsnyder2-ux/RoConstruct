// from server: 57% by atomic.potato
struct S
{
    void f(float* p);
};

extern "C" float* __cdecl sub_53fac0();
extern float g_00a63b14;

void S::f(float* p)
{
    float* q = sub_53fac0();
    p[0] = q[0];
    p[3] = g_00a63b14;
    p[1] = q[1];
    p[2] = q[2];
}

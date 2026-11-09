// from server: 83% by atomic.potato
struct S_func_006f2950 {
    char pad0[572];
    float x;
    float y;
    void f(float* p);
};

void S_func_006f2950::f(float* p)
{
    p[0] = x;
    p[1] = y;
}

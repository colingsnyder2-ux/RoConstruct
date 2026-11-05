// from server: 100% by atomic.potato
struct S
{
    int f(float*);
};

extern "C" float* __cdecl sub_62BA30();

int S::f(float* p)
{
    float* q = sub_62BA30();
    p[0] = q[0];
    p[1] = q[1];
    p[2] = q[2];
    return (int)p;
}

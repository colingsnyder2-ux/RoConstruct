// from server: 67% by atomic.potato
extern "C" float* __cdecl sub_627310();

float* __cdecl sub_4acaf0(float* a, float* b, float* c)
{
    float* p = sub_627310();
    c[0] = p[0];
    c[1] = p[1];
    b[0] += a[0];
    b[1] += a[1];
    return b;
}

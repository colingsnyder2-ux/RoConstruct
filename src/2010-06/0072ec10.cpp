// from server: 96% by atomic.potato
struct S
{
    float x;
    float y;
    S& __cdecl f(float);
};

extern "C" float* __cdecl sub_611ad0(float*);

S& S::f(float value)
{
    float* p = sub_611ad0(&value);
    x = p[0];
    y = p[1];
    return *this;
}

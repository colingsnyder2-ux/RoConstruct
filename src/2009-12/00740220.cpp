// from server: 34% by atomic.potato
struct S
{
    S(float, float);
};

extern "C" void __cdecl target(float *, int);

S::S(float a, float b)
{
    float v[2];
    v[0] = a;
    v[1] = b;
    target(v, 1);
}

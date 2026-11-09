// from server: 27% by atomic.potato
struct S
{
    static void __stdcall f(float* p, int value);
};

void __stdcall S::f(float* p, int value)
{
    *p = 0.0f;
    p[1] = 1;
    p[2] = 1;
    p[3] = value <= 0 ? 1 : 0;
}

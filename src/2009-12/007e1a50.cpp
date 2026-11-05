// from server: 31% by atomic.potato
struct S
{
    bool __cdecl f(float a, float b);
};

bool S::f(float a, float b)
{
    return !(a > b);
}

// from server: 89% by atomic.potato
struct S
{
    typedef void (__thiscall *Fn)(float, float, float);
    Fn f;
    int a;
    int b;

    void __cdecl g(float, float, float);
};

void S::g(float x, float y, float z)
{
    f(x, y, z);
}

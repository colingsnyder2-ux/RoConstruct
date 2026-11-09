// from server: 95% by atomic.potato
extern "C" void __cdecl Function414DA0(const char*);

struct S
{
    char padding[392];
    void f(int);
    int field_188;
};

void S::f(int value)
{
    if (field_188 != value)
    {
        field_188 = value;
        Function414DA0("dSU3");
    }
}

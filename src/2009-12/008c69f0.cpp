// from server: 100% by atomic.potato
struct S
{
    char padding[32];
    int field20;
    void f();
};

extern "C" void __stdcall target(int);

void S::f()
{
    if (field20 != 0)
        target(0);
}

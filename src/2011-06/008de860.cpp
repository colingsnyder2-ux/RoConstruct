// from server: 100% by atomic.potato
struct S
{
    char padding[32];
    int field_20;
    void f();
};

extern "C" void __stdcall target(int);

void S::f()
{
    if (field_20 != 0)
        target(0);
}

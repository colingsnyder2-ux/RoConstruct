// from server: 90% by atomic.potato
extern "C" void __cdecl sub_0080b15d(int);

int g_00cce704;
int g_00cce708;

struct S
{
    int f();
};

int S::f()
{
    sub_0080b15d(g_00cce708);
    return g_00cce704;
}

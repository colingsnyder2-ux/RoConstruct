// from server: 87% by atomic.potato
struct PhysicsJob {
    char pad[0x1d0];
    double field_1d0;
    void method(int a, int b);
};

extern bool g_flag;
extern double g_default;

void PhysicsJob::method(int a, int b)
{
    double v;
    if (g_flag)
        v = field_1d0;
    else
        v = g_default;
    extern void __stdcall helper(int, int, double);
    helper(a, b, v);
}

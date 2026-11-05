// from server: 87% by atomic.potato
struct PhysicsJob {
    char pad[0x1d0];
    double field_1d0;
    void sub_59c8e0(int, int);
};

extern bool g_flag_ba84a8;
extern double g_double_a12668;

extern "C" void __stdcall sub_79bdd0(int, int, double);

void PhysicsJob::sub_59c8e0(int a, int b) {
    double v;
    if (g_flag_ba84a8)
        v = field_1d0;
    else
        v = g_double_a12668;
    sub_79bdd0(a, b, v);
}

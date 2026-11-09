// from server: 100% by atomic.potato
struct RBX_PhysicsJob {
    char pad_0[0x1d0];
    double f_1d0;
    void* run(void* a, void* b);
};

extern "C" void* __stdcall func_0070c990(void* a, void* b, double v);

extern char g_a06090;
extern double g_8bcf78;

void* RBX_PhysicsJob::run(void* a, void* b) {
    double v;
    if (g_a06090)
        v = f_1d0;
    else
        v = g_8bcf78;
    func_0070c990(a, b, v);
    return a;
}

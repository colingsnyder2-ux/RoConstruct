// from server: 100% by atomic.potato
struct RBX_PhysicsJob {
    char pad_0[0x1e0];
    double field_1e0;
    void* method(int, int);
};

extern "C" void* __stdcall func_007fddb0(int, int, double);
extern double g_00a690d8;
extern char g_00c45238;

void* RBX_PhysicsJob::method(int b, int c) {
    double v;
    if (g_00c45238) {
        v = field_1e0;
    } else {
        v = g_00a690d8;
    }
    func_007fddb0(b, c, v);
    return (void*)b;
}

// from server: 100% by atomic.potato
extern "C" void __stdcall sub_977D20(int, int, double);

extern double dword_B53AF0;
extern char byte_DA37A0;

struct PhysicsJob {
    char pad[0x218];
    double field_218;
    int method(int, int);
};

int PhysicsJob::method(int a, int b) {
    double v;
    if (byte_DA37A0) {
        v = field_218;
    } else {
        v = dword_B53AF0;
    }
    sub_977D20(a, b, v);
    return a;
}

// from server: 41% by atomic.potato
struct S {
    char pad0[0x3c];
    int f(int);
};

extern "C" void __stdcall sub_4C6870();
extern "C" void __stdcall sub_80B0AC();
extern "C" void __stdcall sub_801F00();

int S::f(int arg) {
    int v;
    v = arg;
    if (v == -4) {
        sub_4C6870();
        sub_80B0AC();
    } else if (v < 0 || v > 1) {
        sub_801F00();
        sub_80B0AC();
    }
    return 0;
}

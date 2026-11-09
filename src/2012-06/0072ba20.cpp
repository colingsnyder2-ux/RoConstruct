// from server: 59% by atomic.potato
struct X_0072ba20 {
    char pad_0[0x18];
    int f_18;
    int f_1c;
    int f_20;
    int run(int a, int b);
};

int X_0072ba20::run(int a, int b) {
    X_0072ba20* p = (X_0072ba20*)a;
    if (p != 0) {
        p = (X_0072ba20*)((char*)p - 0x1c);
    } else {
        p = 0;
    }
    int idx = f_20;
    int* base = (int*)((char*)p + 0xa8);
    int v = base[idx];
    v += f_1c;
    int (*fn)(int, int) = (int (*)(int, int))f_18;
    return fn((int)((char*)p + 0xa8 + v), b);
}

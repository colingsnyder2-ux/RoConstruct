// from server: 59% by atomic.potato
struct X_0072baa0 {
    char pad_0[0x18];
    int f_18;
    int f_1c;
    int f_20;
    int run(int a, int b);
};

int X_0072baa0::run(int a, int b) {
    X_0072baa0* p;
    if (a != 0) {
        p = (X_0072baa0*)((char*)a - 0x1c);
    } else {
        p = 0;
    }
    int v = *(int*)b;
    int idx = f_20;
    int base = *(int*)((char*)p + 0xa8);
    int off = *(int*)(base + idx);
    off += f_1c;
    int (*fn)(int) = (int (*)(int))f_18;
    return fn(off + (int)p + 0xa8);
}

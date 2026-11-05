// from server: 75% by atomic.potato
struct X_0073bcf0 {
    char pad_0[0xac];
    int f_ac;
    int f_b0;
    int get(int* a, int* b);
    int run(int arg);
};

int X_0073bcf0::run(int arg) {
    int a;
    int b;
    get(&a, &b);
    if (a != f_b0) {
        return *(int*)(a + 0x28);
    }
    return 0;
}

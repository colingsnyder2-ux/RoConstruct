// from server: 45% by atomic.potato
struct X_0043fc40 {
    char pad_0[8];
    int f_8;
    int f_c;
    void invoke(int* arg1, int* arg2);
};

void X_0043fc40::invoke(int* arg1, int* arg2) {
    int* p = arg1;
    if (p != 0) {
        int v = *arg2;
        int off = f_c;
        void (*fn)(int) = (void (*)(int))f_8;
        off += (int)p - 0x18;
        fn(off);
    } else {
        int v = *arg2;
        int off = f_c;
        void (*fn)(int) = (void (*)(int))f_8;
        off += 0;
        fn(off);
    }
}

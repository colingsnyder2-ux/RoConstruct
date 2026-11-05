// from server: 82% by atomic.potato
extern int g_00CB37C4;

struct S {
    char pad[0x10d];
    char flag;
    void f();
};

void S::f() {
    if (g_00CB37C4 != 0)
        return;
    flag = 1;
}

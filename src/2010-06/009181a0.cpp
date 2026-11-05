// from server: 23% by atomic.potato
struct GfxAttachement {
    char pad0[4];
    void sub_919410(int, int*, int, char);
    void func(int);
};

void GfxAttachement::func(int a) {
    int v = a;
    char b = 0;
    sub_919410(0, &v, (int)this, b);
}

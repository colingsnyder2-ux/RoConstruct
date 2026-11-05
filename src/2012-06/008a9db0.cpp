// from server: 68% by atomic.potato
struct DecalTool {
    char pad[0x60];
    struct Vtbl {
        virtual void f();
    } *vptr;
    void sub_8a9db0(int);
};

void DecalTool::sub_8a9db0(int a) {
    int t = *(int*)(a + 0x10);
    if (t == 0x7f || t == 0x1b) {
        vptr->f();
    }
}

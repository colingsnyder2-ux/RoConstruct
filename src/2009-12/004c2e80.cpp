// from server: 64% by atomic.potato
struct S_func_00484cb0 {
    char pad0[2088];
    int m_x;
    int f();
};

struct S_004f2330 {
    char pad0[0x238];
    char f();
};

extern "C" void __stdcall f_004f2270();
extern "C" void __stdcall f_00580620();

struct RbxPartBinding {
    char pad0[0x24];
    char *m_p24;
    char pad1[0x58 - 0x28];
    char m_b58;
    void func();
};

void RbxPartBinding::func()
{
    f_004f2270();
    char *p = m_p24;
    if (((S_004f2330 *)(p + 0x238))->f()) {
        m_b58 = 1;
        char *q = m_p24;
        int *r = *(int **)(q + 0x1e4);
        int *s = *(int **)((char *)r + 0x47d8);
        S_func_00484cb0 *obj = (S_func_00484cb0 *)(q + 0x238);
        int v = obj->f();
        f_00580620();
    }
}

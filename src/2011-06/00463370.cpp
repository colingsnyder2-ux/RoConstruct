// from server: 88% by atomic.potato
struct SInner_00463370 {
    void release(int);
};

struct S_func_00463370 {
    unsigned char _pad0[0xb2];
    unsigned char flag;
    unsigned char _pad1[0x59];
    SInner_00463370* inner;
    int f(int a1, int a2, int a3, int* a4);
};

int S_func_00463370::f(int a1, int a2, int a3, int* a4)
{
    if (flag == 0) {
        *a4 = 0;
        return 0;
    }
    *a4 = 0;
    SInner_00463370* p = inner;
    if (p != 0) {
        p->release(0);
    }
    return 0;
}

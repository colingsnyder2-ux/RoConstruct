// from server: 100% by tester
struct S_func_00573890 {
    char pad0[420];
    int m_x;
    int* f();
};

struct S_func_005b9630 {
    void g(int a1, int a2);
};

struct S_func_005b7d00 {
    void h(int a1, int a2, int a3);
};

void S_func_005b7d00::h(int a1, int a2, int a3)
{
    S_func_00573890* p;
    if (a1 != 0) {
        p = (S_func_00573890*)(a1 - 4);
    } else {
        p = 0;
    }
    int* r = p->f();
    S_func_005b9630* q = (S_func_005b9630*)r;
    q->g(a2, a3);
}

// from server: 24% by tester
struct S_func_00867e00 {
    char pad0[4];
    int m_x;
    int* f();
};

int* S_func_00867e00::f()
{
    return &m_x;
}

struct S_func_004c1790 {
    char pad0[0x20];
    void f(int* a, int* b);
};

struct S_func_0094f920 {
    void f(int* a, int* b, int* c, int* d);
};

struct S_func_00929280 {
    void f(int* a);
};

struct S_func_00930a20 {
    int f(int a, int b, int c);
};

struct S_func_00930eb0 {
    char pad0[0x20];
    void* m_ptr20;
    void f(int a, int b, int c, int d);
};

void S_func_00930eb0::f(int a, int b, int c, int d)
{
    int v10;
    int v20;
    int v14;
    int v4;
    int v24;
    int v28;

    S_func_004c1790* p1 = (S_func_004c1790*)c;
    p1->f((int*)&v10, ((S_func_00867e00*)a)->f());

    S_func_004c1790* p2 = (S_func_004c1790*)c;
    p2->f((int*)&v20, ((S_func_00867e00*)b)->f());

    v14 = -1;
    v4 = -1;

    ((S_func_0094f920*)m_ptr20)->f((int*)&v10, (int*)&v20, &v14, &v4);

    if (v14 != -1) {
        v24 = ((S_func_00930a20*)this)->f(v14, a, b);
        ((S_func_00929280*)d)->f(&v24);
    }

    if (v4 != -1) {
        v28 = ((S_func_00930a20*)this)->f(v4, a, b);
        ((S_func_00929280*)d)->f(&v28);
    }
}

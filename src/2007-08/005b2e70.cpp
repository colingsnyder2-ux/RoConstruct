// from server: 100% by colin
struct S_func_005b0a00 {
    void* f();
};

struct S_func_00541630 {
    void g(int);
};

struct S_func_005b2e70 {
    void f(int, int);
};

void S_func_005b2e70::f(int a1, int a2)
{
    S_func_005b0a00* p = (S_func_005b0a00*)((char*)a2 + 0x18);
    void* r = p->f();
    int* q = (int*)r;
    int v = *q;
    if (v != 0) {
        ((S_func_00541630*)v)->g(0);
    }
}

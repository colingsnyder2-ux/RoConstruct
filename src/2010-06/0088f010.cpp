// from server: 100% by atomic.potato
struct Sub {
    int get(int);
};

struct S {
    char pad[0x74];
    Sub sub;
    void f(int a);
    void g(int, int);
};

void S::f(int a) {
    if (a == -1) return;
    int* p = (int*)sub.get(a);
    int* r = (int*)p[2];
    if (!r) return;
    int* q = (int*)r[5];
    g(q[0], q[1]);
}

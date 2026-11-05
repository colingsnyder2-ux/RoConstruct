// from server: 88% by atomic.potato
struct Inner {
    char pad0[4];
    int* data;
    int count;
    int get(int idx);
};

struct Outer {
    char pad0[0x74];
    Inner list;
    void doIt(int a, int b);
    void f(int idx);
};

void Outer::f(int idx) {
    if (idx == -1)
        return;
    Inner* p = &list;
    int* e = (int*)p->get(idx);
    if (e == 0)
        return;
    int* q = (int*)e[5];
    doIt(q[0], q[1]);
}

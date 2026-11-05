// from server: 72% by atomic.potato
struct S {
    char pad[8];
    int offset8;
    int f(int, int);
};

struct T {
    int f(int *, int *);
};

int S::f(int a, int b) {
    int tmp = 0;
    int *p = (int *)a;
    if (p != 0) {
        p = (int *)((char *)p - 0x1c);
    } else {
        p = 0;
    }
    int *esi = (int *)((char *)this->offset8 + (int)p);
    int *edi = (int *)b;
    ((T *)edi)->f(edi, esi);
    edi[7] = esi[7];
    return (int)edi;
}

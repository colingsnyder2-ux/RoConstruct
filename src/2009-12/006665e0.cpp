// from server: 77% by atomic.potato
struct S {
    void f(int* arg);
    int m0;
    int m4;
    int m8;
    int m12;
    int m16;
};

void S::f(int* arg)
{
    int* p;
    if (m16 == 0)
        p = 0;
    else
        p = (int*)m8;

    if (p == 0)
        return;

    while (1) {
        double a = *(double*)((char*)arg + 8);
        double b = *(double*)p;
        if (b > a)
            (*arg)++;
        p = (int*)((char*)p + 8);
        if (p == (int*)m4)
            p = (int*)m0;
        if (p == (int*)m12)
            break;
        if (p == 0)
            break;
    }
}

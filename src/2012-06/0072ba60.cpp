// from server: 48% by atomic.potato
struct S_0072ba60
{
    void (*f_8)(void*);
    int f_c;
    int f_10;
    int f_a8;

    void* f(void* x);
};

void* S_0072ba60::f(void* x)
{
    S_0072ba60* p;
    if (x)
        p = (S_0072ba60*)((char*)x - 0x1c);
    else
        p = 0;
    f_8((char*)p->f_a8 + f_10 + f_c);
    return 0;
}

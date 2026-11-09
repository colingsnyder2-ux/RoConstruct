// from server: 86% by atomic.potato
extern "C" void sub_004ec9e0(void *, void *, unsigned int, unsigned int);
extern "C" void sub_004f05b0(void *, void *);

struct S_func_00521d00 {
    void f(void *);
};

void S_func_00521d00::f(void *p)
{
    sub_004ec9e0(this, p, 0x20, 1);
    *(unsigned int *)p = ~*(unsigned int *)p;
    sub_004f05b0(this, (char *)p + 4);
}

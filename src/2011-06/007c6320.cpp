// from server: 70% by atomic.potato
extern "C" void sub_7c4fa0(void *, int, int);

struct S
{
    S *f(int a);
};

S *S::f(int a)
{
    sub_7c4fa0(this, a, a);
    *(int *)this = 0xabd66c;
    *(int *)((char *)this + 0xd0) = 0;
    return this;
}

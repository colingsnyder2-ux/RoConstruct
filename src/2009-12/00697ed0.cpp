// from server: 54% by atomic.potato
struct S
{
    int f();
};

extern "C" void sub_5395b0(void *);
extern "C" void sub_6979a0(S *, int);

int S::f()
{
    sub_5395b0((char *)this + 0x1bc);
    sub_6979a0(this, 0);
    return 0;
}

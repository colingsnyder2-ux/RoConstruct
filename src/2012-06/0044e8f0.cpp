// from server: 69% by atomic.potato
struct S
{
    int *f(int);
};

void sub_44d8d0(S *, int);

int *S::f(int value)
{
    sub_44d8d0(this, value);
    *(int *)((char *)this + 0x3c) = 0x00b43c34;
    *(int *)this = 0x00b531c8;
    *(int *)((char *)this + 0x28) = 0x00b531c0;
    *(int *)((char *)this + 0x3c) = 0x00b531b0;
    return (int *)this;
}

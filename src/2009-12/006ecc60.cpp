// from server: 69% by atomic.potato
struct S
{
    int f();
};

extern "C" void sub_006ecbf0(S *, int);

int S::f()
{
    int value;
    if (*((int *)((char *)this + 0xb8)) > 0)
        value = **((int **)((char *)this + 0xb4));
    else
        value = 0;
    sub_006ecbf0(this, value);
    return 0;
}

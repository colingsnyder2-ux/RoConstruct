// from server: 63% by atomic.potato
struct S
{
    int f();
};

extern "C" int sub_5ddae0(S *);
extern "C" void sub_597910(int *, int);

int S::f()
{
    int *p;
    do
    {
        p = (int *)sub_5ddae0(this);
        if (!p)
            break;
        sub_597910(p, 0);
    } while (sub_5ddae0(this));
    return 0;
}

// from server: 73% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int sub_005473c0(S *, int);
extern "C" int sub_0076a190(S *, int *);

int S::f(int value)
{
    int *p = (int *)sub_005473c0(this, value + 4);
    int v = *p;
    return sub_0076a190(this, &v);
}

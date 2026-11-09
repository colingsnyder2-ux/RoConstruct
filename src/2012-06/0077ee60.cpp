// from server: 73% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int sub_76c4f0(S *, int);
extern "C" int sub_76a190(S *, int *);

int S::f(int value)
{
    int *p = (int *)sub_76c4f0(this, value + 4);
    int v = *p;
    return sub_76a190(this, &v);
}

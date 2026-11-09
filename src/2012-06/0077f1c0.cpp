// from server: 73% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int sub_7c5e70(S *, int);
extern "C" int sub_76a190(S *, int *);

int S::f(int a)
{
    int v = sub_7c5e70(this, a + 4);
    int x = *(int *)v;
    return sub_76a190(this, &x);
}

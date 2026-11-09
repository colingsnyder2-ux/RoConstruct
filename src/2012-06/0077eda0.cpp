// from server: 75% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int sub_76ba00(int);
extern "C" int sub_76a190(S *, int *);

int S::f(int value)
{
    int x;
    x = sub_76ba00(value + 4);
    x = *(int *)x;
    return sub_76a190(this, &x);
}

// from server: 79% by atomic.potato
struct S
{
    int f(int *);
};

extern "C" int *__cdecl sub_76ccd0(int *);
extern "C" int sub_76a190(S *, int *);

int S::f(int *p)
{
    int *q = sub_76ccd0(p + 1);
    int v = *q;
    return sub_76a190(this, &v);
}

// from server: 79% by atomic.potato
struct S
{
    int f(int *);
};

extern "C" int *__cdecl sub_694D60(int *);
extern "C" int sub_76A190(S *, int *);

int S::f(int *p)
{
    int *q = sub_694D60(p + 1);
    int v = *q;
    return sub_76A190(this, &v);
}

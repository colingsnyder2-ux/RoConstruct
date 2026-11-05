// from server: 60% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int __cdecl sub_442600(int *, int);

int S::f(int a)
{
    int v = (*(int (**)(int *, int))(*(int **)this + 0x3c))((int *)this, a);
    return sub_442600(&v, v);
}

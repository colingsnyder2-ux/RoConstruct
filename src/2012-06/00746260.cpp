// from server: 100% by atomic.potato
extern "C" int __cdecl sub_00827450(int);

struct S
{
    void f(int a, char b);
};

void S::f(int a, char b)
{
    if (b != 0)
    {
        *(int *)this |= sub_00827450(a);
    }
    else
    {
        *(int *)this &= ~sub_00827450(a);
    }
}

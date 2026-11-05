// from server: 87% by atomic.potato
extern "C" int __cdecl sub_833810(int, int, int);
extern "C" void sub_b2263c(void *);

struct S
{
};

int __cdecl f(int a)
{
    int x = sub_833810(a, 1, *(int *)0xde18b4);
    sub_b2263c((void *)x);
    return 0;
}

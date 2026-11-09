// from server: 77% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int __cdecl sub_74ce20(int, int, int);

int S::f(int value)
{
    return sub_74ce20(((int *)this)[3], ((int *)this)[2], value);
}

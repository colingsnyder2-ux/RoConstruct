// from server: 95% by atomic.potato
extern "C" int __cdecl sub_491b70(int, int);

struct S
{
    int f(int);
};

int S::f(int value)
{
    int *p = *(int **)((char *)this - 0x238);
    int result = ((int (__thiscall *)(int *))p[0x168 / 4])(
        (int *)((char *)this - 0x238 + 0));
    sub_491b70(value, result);
    return value;
}

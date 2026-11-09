// from server: 50% by atomic.potato
extern "C" int __cdecl sub_5A3120(int, int);
extern "C" int __cdecl sub_5A5930(int);

struct S
{
    int value;
    int f(int);
};

int S::f(int arg)
{
    int result = sub_5A3120(value, 11);
    result = sub_5A5930(result);
    *(int *)arg = 1;
    return ((int (__cdecl *)(int))(*(int **)(*(int *)arg)))(arg);
}
